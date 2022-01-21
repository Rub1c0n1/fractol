/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:28:59 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:28:59 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*num_convert_hex_pointer_p(char *s, unsigned long num, int i)
{
	s[0] = '0';
	s[1] = 'x';
	s[2] = '0';
	s[3] = '0';
	s[i + 4] = '\0';
	while (i)
	{
		i--;
		if (num % 16 >= 10)
			s[i + 4] = 'a' + num % 16 - 10;
		else
			s[i + 4] = '0' + num % 16;
		num /= 16;
	}
	return (s);
}

char	*pointer_to_hex(size_t num)
{
	char			*s1;
	int				i;
	unsigned long	r;

	i = 0;
	r = num;
	while (r)
	{
		r /= 16;
		i++;
	}
	s1 = (char *)malloc(sizeof(char) * i + 6);
	if (!s1)
		return (NULL);
	s1 = num_convert_hex_pointer_p(s1, num, i);
	return (s1);
}
