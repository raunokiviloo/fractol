/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:01:02 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/17 13:02:35 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, t_fract *fractol)
{
	if (keysym == XK_Escape)
		exit_program(fractol);
	return (0);
}

int	handle_redcross(t_fract *fractol)
{
	exit_program(fractol);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fract *fractol)
{
	double		zoom;
	double		mouse_real;
	double		mouse_imaginary;
	double		range_real;
	double		range_imaginary;

	if (button == MWHLUP)
		zoom = 1.1;
	else if (button == MWHLDWN)
		zoom = 0.9;
	else
		return (0);
	range_real = fractol->real_max - fractol->real_min;
	range_imaginary = fractol->imaginary_max - fractol->imaginary_min;
	mouse_real = fractol->real_min + x * range_real / (double)WIDTH;
	mouse_imaginary = fractol->imaginary_max - y
		* range_imaginary / (double)HEIGHT;
	fractol->real_min += (mouse_real - fractol->real_min) * (1 - zoom);
	fractol->real_max = fractol->real_min + range_real * zoom;
	fractol->imaginary_max -= (fractol->imaginary_max
			- mouse_imaginary) * (1 - zoom);
	fractol->imaginary_min = fractol->imaginary_max - range_imaginary * zoom;
	render(fractol);
	return (0);
}
