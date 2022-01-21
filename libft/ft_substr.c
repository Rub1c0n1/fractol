/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:30 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*startbigger(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) + 1);
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = startbigger();
		return (substr);
	}
	if (ft_strlen(s) > len)
		substr = (char *)malloc(sizeof(char) * (len + 1));
	else
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!substr)
		return (NULL);
	while (s[i] && j < len && i >= start)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
