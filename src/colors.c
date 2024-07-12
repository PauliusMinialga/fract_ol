/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/08 09:24:29 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 10:00:22 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialize_palette(t_fractal *fractal)
{
	int		i;
	int		r;
	int		g;
	int		b;
	double	f;

	i = 1;
	fractal->palette[0] = 0xFF;
	while (i < MAXITER)
	{
		f = (double)i / (MAXITER / 2);
		r = (int)(fractal->colour.red * (1 - f) * f * f * f * 255);
		g = (int)(fractal->colour.green * (1 - f) * (1 - f) * f * f * 255);
		b = (int)(fractal->colour.blue * (1 - f) * (1 - f) * (1 - f) * f * 255);
		fractal->palette[i] = (r << 24) | (g << 16) | (b << 8) | 255;
		i++;
	}
}

void	shift_palette(t_fractal *fractal)
{
	fractal->colour.red += 0.5;
	fractal->colour.green += 0.5;
	fractal->colour.blue += 0.5;
	initialize_palette(fractal);
}
