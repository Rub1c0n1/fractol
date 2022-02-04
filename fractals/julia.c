//
// Created by Deadshot Gizzard on 2/4/22.
//
#include "../fractol.h"

void julia(t_info *e, t_lims lims)
{
	t_cmp 	cmp;
	double 	x_new;
	int 	iteration;
	int		cx;
	int		cy;
	int		row;
	int		col;

	row = 0;
	col = 0;
	if (e->julia_params.c_re == -10 && e->julia_params.c_im == -10)
		mlx_mouse_get_pos(e->mlx_win, &cx, &cy);
	else
	{
		cx = e->julia_params.c_re;
		cy = e->julia_params.c_im;
	}
	printf("%d %d \n", cx, cy);
	while (row < 1080)
	{
		while (col < 1920)
		{
			cmp.c_re = lims.min_x + (double)cx / 1920 * (lims.max_x - lims.min_x);
			cmp.c_im = lims.min_y + (double)cy / 1080 * (lims.max_y - lims.min_y);
			cmp.x = lims.min_x + (double)col / 1920 * (lims.max_x - lims.min_x);
			cmp.y = lims.min_y + (double)row / 1080 * (lims.max_y - lims.min_y);
			iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < lims.max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				iteration++;
			}
			if (iteration < lims.max_iter)
				my_mlx_pixel_put((&e->data), col, row, iteration * 0x00332211);
			else
				my_mlx_pixel_put(&(e->data), col, row, 0x00000000);
			col++;
		}
		row++;
	}
}