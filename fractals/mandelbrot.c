//
// Created by Deadshot Gizzard on 2/4/22.
//
#include "../fractol.h"

void	mandelbrot(t_data *data, t_lims lims)
{
	t_cmp	cmp;
	double	x_new;
	int		iteration;
	int 	row;
	int 	col;

	row = 0;
	col = 0;
	while (row < 1080)
	{
		printf("%d\n", row);
		cmp.c_im = lims.min_y + (double)row / 1080 * (lims.max_y - lims.min_y);
		while (col < 1920)
		{
			cmp.c_re = lims.min_x + (double)col / 1920 * (lims.max_x - lims.min_x);
			cmp.x = 0;
			cmp.y = 0;
			iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < lims.max_iter)
			{
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				iteration++;
			}
			if (iteration < lims.max_iter)
				my_mlx_pixel_put(data, col, row, iteration * 0x00ffaa11);
			else
				my_mlx_pixel_put(data, col, row, 0x00000000);
			col++;
		}
		row++;
	}
}


//void	mandelbrot(t_data *data, t_lims lims)
//{
//	t_cmp	cmp;
//	double	x_new;
//	int		iteration;
//
//	for (int row = 0; row < 1080; row++)
//	{
//		cmp.c_im = lims.min_y + (double)row / 1080 * (lims.max_y - lims.min_y);
//		for (int col = 0; col < 1920; col++)
//		{
//			cmp.c_re = lims.min_x + (double)col / 1920 * (lims.max_x - lims.min_x);
//			cmp.x = 0;
//			cmp.y = 0;
//			iteration = 0;
//			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < lims.max_iter) {
//				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
//				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
//				cmp.x = x_new;
//				iteration++;
//			}
//			if (iteration < lims.max_iter)
//				my_mlx_pixel_put(data, col, row, iteration * 0x00ffaa11);
//			else
//				my_mlx_pixel_put(data, col, row, 0x00000000);
//		}
//	}
//}