/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:51:21 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/07 11:24:17 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && n > 0)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		}
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
