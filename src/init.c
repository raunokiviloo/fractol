/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkiviloo <rkiviloo@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:03:13 by rkiviloo          #+#    #+#             */
/*   Updated: 2023/01/17 13:04:06 by rkiviloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_args(int argc, char **argv, t_fract *fractol)
{
	if (argc == 2 && *argv[1] == 'M')
	{
		fractol->set = MANDELBROT;
	}
	else if (argc == 2 && *argv[1] == 'J')
	{
		fractol->set = JULIA;
		fractol->k_real = 0.285;
		fractol->k_imaginary = 0.01;
	}
	else if (argc == 4 && *argv[1] == 'J' && ft_atoi(argv[2]) >= -200
		&& ft_atoi(argv[2]) <= 200 && ft_atoi(argv[3]) >= -200
		&& ft_atoi(argv[3]) <= 200)
	{
		fractol->set = JULIA;
		fractol->k_real = convert_k(ft_atoi(argv[2]));
		fractol->k_imaginary = convert_k(ft_atoi(argv[3]));
	}
	else
	{
		print_instructions();
		exit(1);
	}
	return ;
}
/*set_init
- Initializes pixel to complex number mapping by 
defining corner pixel complex values for given set.
- One of the corners is calculated dynamically to avoid image distortion.
*/

void	set_init(t_fract *fractol)
{
	if (fractol->set == MANDELBROT)
	{
		fractol->real_min = -2.0;
		fractol->real_max = 1.0;
		fractol->imaginary_min = -1.5;
		fractol->imaginary_max = fractol->imaginary_min
			+ (fractol->real_max - fractol->real_min) * HEIGHT / WIDTH;
	}
	else if (fractol->set == JULIA)
	{
		fractol->real_min = -2.0;
		fractol->real_max = 2.0;
		fractol->imaginary_min = -2.0;
		fractol->imaginary_max = fractol->imaginary_min
			+ (fractol->real_max - fractol->real_min) * HEIGHT / WIDTH;
	}
}

/*graphics_init
1. Connects to the mlx server via mlx_init
2. Creates a new graphics window via mlx_new_window
3. Creates a new image via mlx_new_image
4. Gets address where we can access pixels via mlx_get_data_addr
*/

void	graphics_init(t_fract *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		ft_printf("Error: Couldn't Connect to MLX");
		exit_program(fractol);
	}
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->win)
	{
		ft_printf("Error: Window Creation Failed");
		exit_program(fractol);
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
	{
		ft_printf("Error: Image Creation Failed");
		exit_program(fractol);
	}
	fractol->buf = mlx_get_data_addr(fractol->img,
			&fractol->pixel_bits, &fractol->line_bytes, &fractol->endian);
	return ;
}
