/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:22:01 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:22:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*arr1;
	size_t			i;

	i = 0;
	arr1 = (unsigned char *)arr;
	while (i < n)
	{
		if (arr1[i] == (unsigned char)c)
			return (&arr1[i]);
		i++;
	}
	return (NULL);
}
