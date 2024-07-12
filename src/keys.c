/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/08 09:54:38 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/27 15:02:08 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_fractal_name(t_fractal *fractal, int value)
{
	if (value == 1)
	{
		fractal->name = "mandelbrot";
		mlx_set_window_title(fractal->mlx, fractal->name);
	}
	else if (value == 2)
	{
		fractal->name = "julia";
		fractal->julia_x = 0;
		fractal->julia_y = 0.8;
		mlx_set_window_title(fractal->mlx, fractal->name);
	}
}

void	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_terminate(fractal->mlx);
	exit(EXIT_SUCCESS);
}

void	my_keyhook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->shift_y -= 0.1;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->shift_y += 0.1;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->shift_x += 0.1;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->shift_x -= 0.1;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_SPACE))
		shift_palette(fractal);
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_1))
		change_fractal_name(fractal, 1);
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_2))
		change_fractal_name(fractal, 2);
	render_fractal(fractal);
}
