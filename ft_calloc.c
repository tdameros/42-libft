/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:01:21 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/09 23:51:10 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	malloc_ptr = (void *) malloc(total_bytes);
	ft_memset(malloc_ptr, 0, total_bytes);
	return (malloc_ptr);
}
