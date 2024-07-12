/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/15 09:44:20 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 09:32:18 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	error_window(void)
{
	ft_putstr_fd("ERROR!\n", 1);
	ft_putstr_fd("Something didn't work with MLX\n", 1);
	exit(EXIT_FAILURE);
}

static void	init_data(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->iterations = 50;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->colour.red = 4;
	fractal->colour.green = 3;
	fractal->colour.blue = 2;
	initialize_palette(fractal);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, true);
	if (fractal->mlx == NULL)
	{
		mlx_terminate(fractal->mlx);
		error_window();
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img
		|| mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0)
	{
		mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
		error_window();
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_scroll_hook(fractal->mlx, &my_scrollhook, fractal);
	mlx_loop_hook(fractal->mlx, (void *)my_keyhook, fractal);
	mlx_close_hook(fractal->mlx, close_window, fractal);
	init_data(fractal);
}
