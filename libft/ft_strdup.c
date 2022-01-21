/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:23:40 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpstr;
	char	*str1;
	int		i;

	i = 0;
	str1 = (char *)str;
	cpstr = malloc(sizeof (char) * ft_strlen(str) + 1);
	if (cpstr == NULL)
		return (0);
	while (str1[i])
	{
		cpstr[i] = str1[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}
