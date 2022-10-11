/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:41:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/10 22:23:50 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_char_ptr;

	s_char_ptr = (unsigned char *) s;
	if (n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		if (s_char_ptr[index] == c)
			return (&(s_char_ptr[index]));
		index++;
	}
	return (NULL);
}
