#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void mandelbrot(t_data *data)
{
	t_cmp 	cmp;
	double 	x_new;
	int 	iteration;
	int		max_iter;

	max_iter = 500;
	for (int row = 0; row < 1080; row++) {
		cmp.c_im = (row - 1080 / 2.0) * 4.0 / 1920;
		for (int col = 0; col < 1920; col++) {
			cmp.c_re = (col - 1920 / 2.0) * 4.0 / 1920;
			cmp.x = 0;
			cmp.y = 0;
			iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				iteration++;
			}
			if (iteration < max_iter)
				my_mlx_pixel_put(data, col, row, iteration * 0x00112233);
			else
				my_mlx_pixel_put(data, col, row, 0x00000000);
		}
	}
}

void julia(void *mlx, t_info data, t_data	img, t_cmp 	cmp, double x_new)
{
	for (int row = 0; row < 1080; row++) {
		for (int col = 0; col < 1920; col++) {
			cmp.c_re = -0.7;
			cmp.c_im = 0.27015;
			cmp.x = (col - 1920 / 2.0) * 4.0 / 1920;
			cmp.y = (row - 1080 / 2.0) * 4.0 / 1920;
			data.iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && data.iteration < data.max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				data.iteration++;
			}
			if (data.iteration < data.max_iter)
				my_mlx_pixel_put(&img, col, row, data.iteration * 0x00221100);
			else
				my_mlx_pixel_put(&img, col, row, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx, data.mlx_win, img.img, 0, 0);
}

int	render(t_info *e)
{
	e->data.img = mlx_new_image(e->mlx, 1920, 1080);
	e->data.addr = mlx_get_data_addr(e->data.img, &(e->data.bits_per_pixel), &(e->data.line_length), &(e->data.endian));
	mandelbrot(&(e->data));
	//julia(e->mlx_win, &(e->data));
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->data.img, 0, 0);
	mlx_destroy_image(e->mlx, e->data.img);
	return (0);
}

void limits_mandelbrot_set(t_lims *lims)
{
	lims->max_x = 2;
	lims->min_x = -2;
	lims->max_y = 1;
	lims->min_y = -1;
	lims->max_iter = 50;
}

int	loop_hook(t_info *e)
{
	render(e);
//	mlx_key_hook(e->win, &key_hook, e);
//	mlx_mouse_hook(e->win, &mouse_hook, e);
	return (0);
}

 int	main(int argc, char* argv[])
{
	void	*mlx;
	t_info	data;
	t_lims	lims;

	if (argc > 1)
	{
		//limits_mandelbrot_set(&lims);
		data.type = argv[1];
		data = *(t_info *)malloc(sizeof(t_info));
		data.mlx = (void *)malloc(sizeof(void *));
		data.mlx_win = (void *)malloc(sizeof(void *));
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "fract-ol");
		mlx_loop_hook(data.mlx, &loop_hook, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
