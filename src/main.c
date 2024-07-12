/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 11:37:32 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 11:24:38 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_function(int value)
{
	if (value == 1)
	{
		ft_putstr_fd("\n\e[1;31mIncorrect input!\n\n", 1);
		ft_putstr_fd("\e[0mThe correct input should be:\n", 1);
		ft_putstr_fd("./fractol mandelbrot\n", 1);
		ft_putstr_fd("./fractol julia <real> <imaginary>\n\n", 1);
	}
	if (value == 2)
	{
		ft_putstr_fd("Please provide numbers between -2 and 2!\n", 1);
	}
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0))
	{
		fractal.name = argv[1];
		if (ft_strncmp(fractal.name, "julia", 6) == 0)
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		error_function(1);
	}
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
