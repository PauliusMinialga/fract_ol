/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 12:47:39 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/27 15:05:08 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	(void)xdelta;
	fractal = (t_fractal *)param;
	if (ydelta > 0)
	{
		fractal->zoom *= 0.95;
	}
	else if (ydelta < 0)
	{
		fractal->zoom *= 1.05;
	}
	render_fractal(fractal);
}
