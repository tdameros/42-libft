/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:10:54 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/10 00:30:47 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	index;
	char	*s_dup;

	len = ft_strlen(s);
	index = 0;
	s_dup = malloc(sizeof(char) * (len + 1));
	if (s_dup == NULL)
		return (NULL);
	while (index < len)
	{
		s_dup[index] = s[index];
		index++;
	}
	s_dup[index] = '\0';
	return (s_dup);
}
