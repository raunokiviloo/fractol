/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:06:26 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/17 16:53:48 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_iter(t_fract *fractol, double c_real, double c_imaginary)
{
	double	z_real;
	double	z_imaginary;
	double	tmp;
	int		n;

	z_real = 0;
	z_imaginary = 0;
	n = 0;
	if (fractol->set == MANDELBROT)
	{
		while (n < MAX_ITER)
		{
			if ((z_real * z_real + z_imaginary * z_imaginary) > 4.0)
				break ;
			tmp = 2 * z_real * z_imaginary + c_imaginary;
			z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
			z_imaginary = tmp;
			n++;
		}
	}
	else if (fractol->set == JULIA)
		n = count_julia(fractol, c_real, c_imaginary);
	return (n);
}

int	count_julia(t_fract *fractol, double c_real, double c_imaginary)
{
	double	tmp;
	int		n;

	n = 0;
	while (n < MAX_ITER)
	{
		if ((c_imaginary * c_imaginary + c_real * c_real) > 4.0)
			break ;
		tmp = 2 * c_real * c_imaginary + fractol->k_imaginary;
		c_real = c_real * c_real - c_imaginary
			* c_imaginary + fractol->k_real;
		c_imaginary = tmp;
		n++;
	}
	return (n);
}
/* color_pixel
	Each pixel is represented by 4 bytes, so we 
	multiply by 4 to move pixel-by-pixel
	through the x-axis and multiply by WIDTH * 4 
	to move pixel-by-pixel through the
	y-axis.

	Colors are given in hexadecimal format - AARRGGBB. 
	Each of the components (Alpha, Red, Green, Blue)
	is represented by 2 hexadecimal digits, so 1 byte in total.
*/

void	color_pixel(t_fract *fractol, int x, int y, int iter_count)
{
	int	color;

	if (iter_count == MAX_ITER)
		color = 0x000000;
	if (iter_count < 26)
		color = 0x3c00ff;
	if (iter_count < 24)
		color = 0x00f9ff;
	if (iter_count < 22)
		color = 0x00ff38;
	if (iter_count < 20)
		color = 0xfdff00;
	if (iter_count < 18)
		color = 0xfd00ff;
	if (iter_count < 16)
		color = 0x000000;
	fractol->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
	fractol->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractol->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractol->buf[x * 4 + y * WIDTH * 4] = color;
}

/* render
1. Iterates over every pixel and maps pixel coordinates
to a complex number.
2. Evaluates if a particular pixel 
(represented by a complex number) 
is part of a fractal set
by counting the number of iterations it
 takes for that number to escape the set.
3. Calls a function to color the pixel based 
on the calculated iteration count.
*/

void	render(t_fract *fractol)
{
	int		x;
	int		y;
	double	complex_r;
	double	complex_i;
	int		iter_count;

	mlx_clear_window(fractol->mlx, fractol->win);
	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			complex_r = fractol->real_min + (double)x
				* (fractol->real_max - fractol->real_min) / WIDTH;
			complex_i = fractol->imaginary_max + (double)y
				* (fractol->imaginary_min - fractol->imaginary_max) / HEIGHT;
			iter_count = count_iter(fractol, complex_r, complex_i);
			color_pixel(fractol, x, y, iter_count);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
