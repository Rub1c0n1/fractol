/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:20:00 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:20:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *src)
{
	long long int	i;
	long long int	neg;
	long long int	r;

	r = 0;
	neg = 1;
	i = 0;
	while (src[i] == '\f' || src[i] == '\t' || src[i] == '\r' \
	|| src[i] == '\v' || src[i] == '\n' || src[i] == ' ')
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			neg *= -1;
		i++;
	}
	if (!(src[i] > 47 && src[i] < 58))
		return (0);
	while (src[i] > 47 && src[i] < 58)
		r = (src[i++] - '0') + (r * 10);
	if (r > 2147483648)
		return (-1);
	else if (r < -2147483647 - 1)
		return (0);
	return (neg * r);
}
