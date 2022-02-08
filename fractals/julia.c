/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:52 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:52 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_formule(t_cmp *cmp, t_lims *lims, double *x_new, int *iteration)
{
	while (cmp->x * cmp->x + cmp->y * cmp->y < 4 && *iteration < lims->max_iter)
	{
		*x_new = cmp->x * cmp->x - cmp->y * cmp->y + cmp->c_re;
		cmp->y = 2 * cmp->x * cmp->y + cmp->c_im;
		cmp->x = *x_new;
		(*iteration)++;
	}
}

void	julia(t_info *e, t_lims lims, double row, double col)
{
	t_cmp	cmp;
	double	x_new;
	int		iteration;
	int		cx;
	int		cy;

	mlx_mouse_get_pos(e->mlx_win, &cx, &cy);
	while (row < 1080)
	{
		col = 0;
		while (col < 1920)
		{
			cmp.c_re = lims.minx + (double)cx / 1920 * (lims.max_x - lims.minx);
			cmp.c_im = lims.miny + (double)cy / 1080 * (lims.max_y - lims.miny);
			cmp.x = lims.minx + (double)col / 1920 * (lims.max_x - lims.minx);
			cmp.y = lims.miny + (double)row / 1080 * (lims.max_y - lims.miny);
			iteration = 0;
			julia_formule(&cmp, &lims, &x_new, &iteration);
			print_pixel(iteration, e, col, row);
			col++;
		}
		row++;
	}
}
