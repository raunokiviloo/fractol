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
	double	zoom;

	(void)x;
	(void)y;
	if (button == MWHLUP)
		zoom = 0.5;
	else if (button == MWHLDWN)
		zoom = 2.0;
	else
		return (0);
	fractol->real_min *= zoom;
	fractol->real_max *= zoom;
	fractol->imaginary_min *= zoom;
	fractol->imaginary_max *= zoom;
	render(fractol);
	return (0);
}
