/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:45:39 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/21 15:46:42 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fract	fractol;

	handle_args(argc, argv, &fractol);
	set_init(&fractol);
	graphics_init(&fractol);
	render(&fractol);
	mlx_key_hook(fractol.win, handle_keypress, &fractol);
	mlx_hook(fractol.win, 17, 1L << 17, handle_redcross, &fractol);
	mlx_hook(fractol.win, 4, 1L << 2, handle_zoom, &fractol);
	mlx_loop(fractol.mlx);
}
