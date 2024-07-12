/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_math_too.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 13:09:46 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 11:04:08 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	check_minus(char c)
{
	if (c == '-')
	{
		return (-1.0);
	}
	return (1.0);
}

static double	atodbl_helper(double result, char *str, double sign)
{
	double	power;
	double	final;
	int		i;

	i = 0;
	power = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10.0) + (str[i] - '0');
		power *= 10.0;
		i++;
	}
	final = sign * result / power;
	if (final > 2 || final < -2)
		error_function(2);
	return (final);
}

double	atodbl(char *str)
{
	int		i;
	double	sign;
	double	result;
	double	res;

	i = 0;
	result = 0.0;
	sign = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = check_minus(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	res = atodbl_helper(result, &str[i], sign);
	return (res);
}
