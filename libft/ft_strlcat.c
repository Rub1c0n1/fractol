/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:23:56 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:23:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	j;
	unsigned long int	r;

	if (size > ft_strlen(dst))
		r = ft_strlen(dst) + ft_strlen(src);
	else
		r = ft_strlen(src) + size;
	if (size != 0)
	{
		i = 0;
		j = 0;
		while (dst[i])
			i++;
		while (i < size - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	return (r);
}
