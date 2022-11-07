/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:01:21 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/07 22:07:50 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


static size_t	ft_sqrt(size_t nb)
{
	size_t	x;
	size_t	y;

	x = 0.5 * nb + 0.5 * 1;
	y = 1;
	while (x - y >= 1)
	{
		x = 0.5 * (x + y);
		y = nb / x;
	}
	return (x);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_ptr;
	size_t	total_bytes;
	size_t	sqrt_size_max;

	sqrt_size_max = ft_sqrt(SIZE_MAX);
	if (nmemb > sqrt_size_max || size > sqrt_size_max)
		return (NULL);
	total_bytes = nmemb * size;
	malloc_ptr = (void *) malloc(total_bytes);
	if (malloc_ptr == NULL)
		return (NULL);
	ft_bzero(malloc_ptr, total_bytes);
	return (malloc_ptr);
}
