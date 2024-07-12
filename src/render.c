/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/15 09:44:33 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 11:24:29 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	check_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = (scale(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2.0, -2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	check_fractal(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape)
			return (i);
		i++;
	}
	return (MAXITER);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ret = handle_pixel(x, y, fractal);
			if (ret < MAXITER)
				mlx_put_pixel(fractal->img, x, y,
					fractal->palette[ret % MAXITER]);
			else
				mlx_put_pixel(fractal->img, x, y, fractal->palette[0]);
			x++;
		}
		y++;
	}
}
