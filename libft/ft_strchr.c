/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:23:30 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strchr(const char *str, int c)
{
	int			i;
	const char	*str1;

	if (c == '\0')
	{
		str1 = &str[ft_strlen(str)];
		return (str1);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (0);
		else if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
