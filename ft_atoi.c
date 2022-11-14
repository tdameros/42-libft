/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:44:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/14 23:48:45 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	count_white_spaces(const char *s);
static int	check_overflow(const char *str, int result, int sign);

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
		if (index == 9)
			return (check_overflow(str, result, sign));
		result = result * 10 + (str[index] - '0');
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

static int	check_overflow(const char *str, int result, int sign)
{	
	if (ft_isdigit(str[10]))
		return (-1);
	if (result >= INT_MAX / 10 && sign == 1 && str[9] > '7')
		return (-1);
	if (result >= INT_MAX / 10 && sign == -1 && str[9] > '8')
		return (-1);
	if (result == INT_MAX / 10 && sign == -1 && str[9] == '8')
		return (INT_MIN);
	return ((result * 10 + (str[9] - '0')) * sign);
}
