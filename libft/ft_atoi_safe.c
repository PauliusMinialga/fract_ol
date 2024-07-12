/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_safe.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 14:53:22 by pminialg      #+#    #+#                 */
/*   Updated: 2024/01/26 11:40:38 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_minus(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi_safe(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = check_minus(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > __INT_MAX__ / 10 || (result >= __INT_MAX__ / 10
				&& (((sign == 1) && (str[i] > '7'))
					|| ((sign == -1) && str[i] > '8'))))
			return (1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || ((i == 1) && !(str[0] >= '0' && str[0] <= '9')))
		return (1);
	return (0);
}
