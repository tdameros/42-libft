/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:27 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/10 23:01:02 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		index;
	char	*dest_char_ptr;
	char	*src_char_ptr;

	dest_char_ptr = (char *) dest;
	src_char_ptr = (char *) src;
	index = n - 1;
	while (index >= 0)
	{
		dest_char_ptr[index] = src_char_ptr[index];
		index--;
	}
	return (dest_char_ptr);
}
