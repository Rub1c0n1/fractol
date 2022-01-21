#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

 int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_cmp 	cmp;
	int 	max_iter;
	int 	iteration;
	double 	x_new;

	max_iter = 400;
	img.params.height = 1080;
	img.params.width = 1920;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.params.width, img.params.height, "Hello world!");
	img.img = mlx_new_image(mlx, img.params.width, img.params.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int row = 0; row < img.params.height; row++) {
		for (int col = 0; col < img.params.width; col++) {
			cmp.c_re = -0.7;
			cmp.c_im = 0.27015;
			cmp.x = (col - img.params.width / 2.0) * 4.0 / img.params.width;
			cmp.y = (row - img.params.height / 2.0) * 4.0 / img.params.width;
			iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				iteration++;
			}
			if (iteration < max_iter)
				my_mlx_pixel_put(&img, col, row, 0x00FFFFFF + iteration * 20);
			else
				my_mlx_pixel_put(&img, col, row, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


//Mandelbrot set
//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
//	t_cmp 	cmp;
//	int		height;
//	int		width;
//	int 	max;
//	int 	iteration;
//	double 	x_new;
//
//	max = 1000;
//	height = 1080;
//	width = 1920;
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
//	img.img = mlx_new_image(mlx, width, height);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			cmp.c_re = (col - width / 2.0) * 4.0 / width;
//			cmp.c_im = (row - height / 2.0) * 4.0 / width;
//			cmp.x = 0;
//			cmp.y = 0;
//			iteration = 0;
//			while (cmp.x * cmp.x + cmp.y * cmp.y <= 4 && iteration < max) {
//				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
//				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
//				cmp.x = x_new;
//				iteration++;
//			}
//			if (iteration < max)
//				my_mlx_pixel_put(&img, col, row, 0x00FFFFFF);
//			else
//				my_mlx_pixel_put(&img, col, row, 0x00000000);
//		}
//	}
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}
