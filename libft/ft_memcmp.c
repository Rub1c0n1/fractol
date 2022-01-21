/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:22:06 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:22:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *lhs, const void *rhs, size_t n)
{
	unsigned long	i;
	unsigned char	*lhs1;
	unsigned char	*rhs1;

	lhs1 = (unsigned char *)lhs;
	rhs1 = (unsigned char *)rhs;
	i = 0;
	while (*lhs1 == *rhs1 && ++i < n)
	{
		lhs1++;
		rhs1++;
	}
	if (n == 0)
		return (0);
	return ((int)(*lhs1 - *rhs1));
}
