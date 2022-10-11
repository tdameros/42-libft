/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:31:20 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/08 23:36:47 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;
	char	*s;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	index = 0;
	s = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (s == NULL)
		return (NULL);
	while (index < len_s1)
	{
		s[index] = s1[index];
		index++;
	}
	index = 0;
	while (index < len_s2)
	{
		s[len_s1 + index] = s2[index];
		index++;
	}
	s[len_s1 + index] = '\0';
	return (s);
}
