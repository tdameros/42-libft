/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:57 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/06 16:59:05 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while ((unsigned char) *s1 == (unsigned char) *s2 && index < n)
	{
		s1++;
		s2++;
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
