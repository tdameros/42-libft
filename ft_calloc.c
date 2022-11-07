/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:01:21 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/07 21:15:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	malloc_ptr = (void *) malloc(total_bytes);
	if (malloc_ptr == NULL)
		return (NULL);
	ft_bzero(malloc_ptr, total_bytes);
	return (malloc_ptr);
}
