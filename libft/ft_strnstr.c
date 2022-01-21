/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:18 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:24:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	j;
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0' && j < len)
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[j + i] == needle[i]
				&& j + i < len)
				++i;
			if (needle[i] == '\0')
				return ((char *)&haystack[j]);
		}
		++j;
	}
	return (0);
}
