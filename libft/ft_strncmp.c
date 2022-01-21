/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:14 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long unsigned int	i;

	i = -1;
	if (n == 0)
		return (0);
	while ((i++, s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		if (s1[i + 1] == '\0' && s2[i + 1] != '\0' && i + 1 < n)
		{
			return ('\0' - (unsigned char) s2[i + 1]);
		}
		if (s1[i + 1] != '\0' && s2[i + 1] == '\0' && i + 1 < n)
		{
			return ((unsigned char) s1[i + 1] - '\0');
		}
	}
	return (0);
}
