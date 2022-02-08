/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:48 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:48 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mand_formule(t_cmp *cmp, t_lims *lims, double *x_new, int *iteration)
{
	while (cmp->x * cmp->x + cmp->y * cmp->y < 4
		&& *iteration < lims->max_iter)
	{
		*x_new = cmp->x * cmp->x - cmp->y * cmp->y + cmp->c_re;
		cmp->y = 2 * cmp->x * cmp->y + cmp->c_im;
		cmp->x = *x_new;
		(*iteration)++;
	}
}

void	print_pixel(int iteration, t_info *e, double col, double row)
{
	if (iteration < e->lims.max_iter)
		my_mlx_pixel_put((&e->data), col, row, iteration * 0x00ffaa11);
	else
		my_mlx_pixel_put((&e->data), col, row, 0x00000000);
}

void	mandelbrot(t_info *e, t_lims lims, double col, double row)
{
	t_cmp	cmp;
	double	x_new;
	int		iteration;

	while (row < 1080)
	{
		cmp.c_im = lims.miny + row / 1080 * (lims.max_y - lims.miny);
		col = 0;
		while (col < 1920)
		{
			cmp.c_re = lims.minx + col / 1920 * (lims.max_x - lims.minx);
			cmp.x = 0;
			cmp.y = 0;
			iteration = 0;
			mand_formule(&cmp, &lims, &x_new, &iteration);
			print_pixel(iteration, e, col, row);
			col++;
		}
		row++;
	}
}
