/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:04:26 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/17 13:05:01 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instructions(void)
{
	ft_printf("\nThis is a simple visualizer for Mandelbrot and Julia sets.\n");
	ft_printf("Credit: http://warp.povusers.org/Mandelbrot/ \n\n");
	ft_printf("To render the Mandelbrot set, use: ./fractol M\n\n");
	ft_printf("Rendering the julia set takes two optional arguments, ");
	ft_printf("which must be integers between -200 and 200.\n");
	ft_printf("E.g., to render the Julia set, use: ./fractol J -76 199\n\n");
	return ;
}

/*exit_program
Exits program, freeing allocated memory based on exit state.
*/

void	exit_program(t_fract *fractol)
{
	if (fractol->img)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->win && fractol->mlx)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(1);
}

double	convert_k(int num)
{
	double	k;

	if (!num)
		return (0);
	k = (double)num * 0.01;
	return (k);
}
