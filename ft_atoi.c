/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:44:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/22 00:33:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	count_white_spaces(const char *s);
static int		check_overflow(const char *str, size_t index, int result, int sign);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	index;

	result = 0;
	sign = 1;
	str += count_white_spaces(str);
	index = 0;
	if (str[index] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[index] == '+')
		str++;
	while (ft_isdigit(str[index]))
	{
		if (LONG_MAX / 10 < result * sign || LONG_MAX - (str[index] - '0') < result * 10 * sign)
			return ((int) LONG_MAX);
		if (LONG_MIN / 10 > result * sign || LONG_MIN + (str[index] - '0') > result * 10 * sign)
			return ((int) LONG_MIN);
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

static size_t	count_white_spaces(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] == ' ' || s[index] == '\f' || s[index] == '\n'
		|| s[index] == '\r' || s[index] == '\t' || s[index] == '\v')
		index++;
	return (index);
}

static int	check_overflow(const char *str, int index,int result, int sign)
{	
	if (LONG_MAX / 10 < result * sign
		|| LONG_MAX - (str[index] - '0') < result * 10 * sign)
		return ((int) LONG_MAX);
	if (LONG_MIN / 10 > result * sign
		|| LONG_MIN + (str[index] - '0') > result * 10 * sign)
		return ((int) LONG_MIN);
}
