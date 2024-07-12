/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_math.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/08 09:52:55 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/27 15:06:14 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	scale(int point, double new_min, double new_max, int old_max)
{
	double	result;
	double	temp;

	temp = (new_max - new_min) * (point);
	result = temp / (old_max) + new_min;
	return (result);
}
