/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:26 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:24:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new_char;
	unsigned int	i2;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i2 = ft_strlen(s1);
	while (i2 && ft_strchr(set, s1[i2]))
		i2--;
	new_char = ft_substr((char *)s1, 0, i2 + 1);
	return (new_char);
}
