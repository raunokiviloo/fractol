#include <mlx.h>
#include <libft.h>
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

#define MLX_ERROR	1
#define WINDOW_WIDTH	500
#define WINDOW_HEIGHT	500

#define MWHLUP	4
#define MWHLDOWN	5

#define ZOOM_DEFAULT_MAX	2
#define ZOOM_DEFAULT_MIN	-2

/*For mandelbrot set, we want to run the equation and see which values trend towards infinity.
We color them based on how many iterations it takes them to escape the bounds of the mandelbrot set.*/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	zoom;
}	t_data;

void	pixel_img_put(t_img *img, int x, int y, int color) //Should create another image as a buffer.
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

double	map_range(double x, double a, double b, double min, double max)
{
	return ((b - a) * (x - min) / (max - min) + a);
}

unsigned long createTRGB(int t, int r, int g, int b)
{
    return ((t << 24) + (r << 16) + (g << 8) + b);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	calc_mandelbrot(int x, int y, t_data data)
{
	int	iterations;
	double	a;
	double	b;
	double	aa;
	double	bb;

	a = map_range(x, -2 * data.zoom, 2 * data.zoom, 0, 500);
	printf("A value: %f\n", a);
	b = map_range(y, -2 * data.zoom, 2 * data.zoom, 0, 500);
	iterations = 0;
	while (iterations < 100)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + map_range(x, -2 * data.zoom, 2 * data.zoom, 0, 500);
		b = bb + map_range(y, -2 * data.zoom, 2 * data.zoom, 0, 500);
		if (ft_abs(a + b) > 16)
			break ;
		iterations++;
	}
	return (iterations);
}

int	color_mandelbrot(int iterations)
{
	int	r;
	int	g;
	int	b;

	if (iterations == 100)
		return (0x000000);
	else
	{
		r = map_range(iterations, 0, 255, 1, 99);
		g = map_range(iterations, 0, 255, 1, 99);
		b = map_range(iterations, 0, 255, 1, 99);
		return (createTRGB(0, r, g, b));
	}
}

int render_img(t_data fractol)
{
	int	x;
	int y;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		y = 0;
		while(y <= WINDOW_HEIGHT)
		{
			calc_mandelbrot(x, y, fractol);
				//pixel_img_put(&fractol.img, x, y, color_mandelbrot(calc_mandelbrot(x, y, fractol)));
			y++;
		}
		x++;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *fractol)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	return (0);
}

int	handle_redcross(t_data *fractol)
{
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	return (0);
}

int	handle_mwheel(int button, t_data *fractol) //SEGFAULTS.
{
	if (button == MWHLUP)
		fractol->zoom *= 0.9;
	else if (button == MWHLDOWN)
	{
		if (fractol->zoom * 1.1 > 1)
			fractol->zoom = 1;
		else
			fractol->zoom *= 1.1;
	}
	if (button == MWHLDOWN || button == MWHLUP)
		render_img(*fractol);
	return (0);	
}

int	handle_no_event(void *data) //Needs to exist for mlx loop to close properly?
{
	(void)data;
	return (0);
}

int main(void)
{
	t_data fractol;

	fractol.mlx_ptr = mlx_init(); //Connect to Mlx instance
	if  (fractol.mlx_ptr == NULL)
		return (MLX_ERROR);

	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol"); //Window creation
	if (fractol.win_ptr == NULL)
	{
		free(fractol.win_ptr);
		return(MLX_ERROR);
	}
	fractol.zoom = 1;
	mlx_hook(fractol.win_ptr, 2, 1L<<0, handle_keypress, &fractol); //Hook for closing window with ESC.
	mlx_hook(fractol.win_ptr, 17, 1L<<17, handle_redcross, &fractol); //Hook for closing window on clicking X.
	mlx_hook(fractol.win_ptr, 4, 1L<<2, handle_mwheel, &fractol),  
	mlx_loop_hook(fractol.mlx_ptr, &handle_no_event, &fractol);
	fractol.img.mlx_img = mlx_new_image(fractol.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); //Create image buffer
	fractol.img.addr = mlx_get_data_addr(fractol.img.mlx_img, &fractol.img.bpp, &fractol.img.line_len, &fractol.img.endian); //Populate img struct
	render_img(fractol);
	mlx_put_image_to_window(fractol.mlx_ptr, fractol.win_ptr, fractol.img.mlx_img, 0, 0);
	mlx_loop(fractol.mlx_ptr); //Rendering stuff
	mlx_destroy_display(fractol.mlx_ptr); //Exit mlx_loop when there is no window left and free memory.
	free(fractol.mlx_ptr);
	exit(0);
}

/* Store zoom variable in struct, init as 1. Increment / decrement by 0.1 on mwheelup / mwheeldown. Redraw as part of the hook.
Rendering needs to be in a separate function.*/