/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:20:11 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:22:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*arr;
	int				i;

	i = 0;
	arr = malloc(number * size);
	if (arr == NULL)
		return (NULL);
	while (arr[i])
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
