/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:44:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 16:00:25 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_white_spaces(const char *s);

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	index;
	int	int_max;

	result = 0;
	sign = 1;
	index = count_white_spaces(nptr);
	int_max = 2147483647;
	if (nptr[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nptr[index] == '+')
		index++;
	while (ft_isdigit(nptr[index]))
	{
		if (result == int_max / 10 && nptr[index] == '8')
			return (int_max * -1 - 1);
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (result * sign);
}

static int	count_white_spaces(const char *s)
{
	int	index;

	index = 0;
	while (s[index] == ' ' || s[index] == '\f' || s[index] == '\n'
		|| s[index] == '\r' || s[index] == '\t' || s[index] == '\v')
		index++;
	return (index);
}
