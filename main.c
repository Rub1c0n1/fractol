#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void mandelbrot(void *mlx, t_info data, t_data	img, t_cmp 	cmp, double x_new)
{
	data.mlx_win = mlx_new_window(mlx, img.params.width, img.params.height, "Mandelbrot Set");
	img.img = mlx_new_image(mlx, img.params.width, img.params.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int row = 0; row < img.params.height; row++) {
		for (int col = 0; col < img.params.width; col++) {
			cmp.c_re = (col - img.params.width / 2.0) * 4.0 / img.params.width;
			cmp.c_im = (row - img.params.height / 2.0) * 4.0 / img.params.width;
			cmp.x = 0;
			cmp.y = 0;
			data.iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && data.iteration < data.max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				data.iteration++;
			}
			if (data.iteration < data.max_iter)
				my_mlx_pixel_put(&img, col, row, 0x00FFFFFF + data.iteration * 20);
			else
				my_mlx_pixel_put(&img, col, row, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx, data.mlx_win, img.img, 0, 0);
}

void julia(void *mlx, t_info data, t_data	img, t_cmp 	cmp, double x_new)
{
	data.mlx_win = mlx_new_window(mlx, img.params.width, img.params.height, "Julia Set");
	img.img = mlx_new_image(mlx, img.params.width, img.params.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int row = 0; row < img.params.height; row++) {
		for (int col = 0; col < img.params.width; col++) {
			cmp.c_re = -0.7;
			cmp.c_im = 0.27015;
			cmp.x = (col - img.params.width / 2.0) * 4.0 / img.params.width;
			cmp.y = (row - img.params.height / 2.0) * 4.0 / img.params.width;
			data.iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && data.iteration < data.max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				data.iteration++;
			}
			if (data.iteration < data.max_iter)
				my_mlx_pixel_put(&img, col, row, 0x00FFFFFF + data.iteration * 20);
			else
				my_mlx_pixel_put(&img, col, row, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx, data.mlx_win, img.img, 0, 0);
}
 int	main(int argc, char* argv[])
{
	void	*mlx;
	t_data	img;
	t_cmp 	cmp;
	t_info	data;
	double 	x_new;

	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "Julia", 6) == 0 || (ft_strncmp(argv[1], "Mandelbrot", 20)) == 0)
		{
			data.max_iter = 400;
			img.params.height = 1080;
			img.params.width = 1920;
			mlx = mlx_init();
			if (ft_strncmp(argv[1], "Julia", 10) == 0)
				julia(mlx, data, img, cmp, x_new);
			else
				mandelbrot(mlx, data, img, cmp, x_new);
			mlx_loop(mlx);
		}

	}
	return (0);
}
