/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:38:38 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/13 16:53:42 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Libraries
# include <mlx.h>
# include <libft.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

// Resolution
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 60

// Sets
# define MANDELBROT 0
# define JULIA 1

// Fractal Struct
typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		set;
	double	real_min;
	double	real_max;
	double	imaginary_min;
	double	imaginary_max;
	double	k_real;
	double	k_imaginary;
	double	cur_r;
	double	cur_i;
}	t_fract;

// Key Symbols
# define MWHLUP 4
# define MWHLDWN 5

// Function Prototypes
void	print_instructions(void);
void	exit_program(t_fract *fractol);
double	convert_k(int num);
void	handle_args(int argc, char **argv, t_fract *fractol);
void	set_init(t_fract *fractol);
void	graphics_init(t_fract *fractol);
int		handle_keypress(int keysym, t_fract *fractol);
int		handle_redcross(t_fract *fractol);
int		count_iter(t_fract *fractol, double c_real, double c_imaginary);
int		count_julia(t_fract *fractol, double c_real, double c_imaginary);
int		color_map(double value);
void	color_pixel(t_fract *fractol, int x, int y, int iter_count);
void	render(t_fract *fractol);
int		handle_zoom(int button, int x, int y, t_fract *fractol);

#endif
