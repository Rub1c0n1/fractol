/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:23:49 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:23:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*prestr;
	char	*poststr;
	char	*joinedstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	prestr = (char *)s1;
	poststr = (char *)s2;
	joinedstr = malloc(sizeof (char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joinedstr == NULL)
		return (NULL);
	while (prestr[i])
	{
		joinedstr[i] = prestr[i];
		i++;
	}
	while (poststr[j])
		joinedstr[i++] = poststr[j++];
	joinedstr[i] = '\0';
	return (joinedstr);
}
