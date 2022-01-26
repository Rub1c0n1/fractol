#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_lims limits_set(t_lims *lims)
{
	if (strncmp(&(lims->type), "mandelbrot", 11))
	{
		lims->max_x = 1;
		lims->min_x = -2;
		lims->max_y = 1;
		lims->min_y = -1;
		lims->max_iter = 50;
	}
	else if (strncmp(&(lims->type), "julia", 6) == 0)
	{
		lims->max_x = 2;
		lims->min_x = -2;
		lims->max_y = 1;
		lims->min_y = -1;
		lims->max_iter = 50;
	}

	return (*lims);
}

void mandelbrot(t_data *data, t_lims lims)
{
	t_cmp 	cmp;
	double 	x_new;
	int 	iteration;

	for (int row = 0; row < 1080; row++) {
		cmp.c_im = lims.min_y + (double)row / 1080 * (lims.max_y - lims.min_y);
		for (int col = 0; col < 1920; col++) {
			cmp.c_re = lims.min_x + (double)col / 1920 * (lims.max_x - lims.min_x);
			cmp.x = 0;
			cmp.y = 0;
			iteration = 0;
			while (cmp.x * cmp.x + cmp.y * cmp.y < 4 && iteration < lims.max_iter) {
				x_new = cmp.x * cmp.x - cmp.y * cmp.y + cmp.c_re;
				cmp.y = 2 * cmp.x * cmp.y + cmp.c_im;
				cmp.x = x_new;
				iteration++;
			}
			if (iteration < lims.max_iter)
				my_mlx_pixel_put(data, col, row, iteration * 0x00ffaa11);
			else
				my_mlx_pixel_put(data, col, row, 0x00000000);
		}
	}
}

void julia(t_info *e, t_lims lims)
{
	t_cmp 	cmp;
	double 	x_new;
	int 	iteration;
	int		cx;
	int		cy;

	mlx_mouse_get_pos(e->mlx_win, &cx, &cy);
	for (int row = 0; row < 1080; row++) {
		for (int col = 0; col < 1920; col++) {
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
		}
	}
}

int	render(t_info *e)
{

	e->data.img = mlx_new_image(e->mlx, 1920, 1080);
	e->data.addr = mlx_get_data_addr(e->data.img, &(e->data.bits_per_pixel), &(e->data.line_length), &(e->data.endian));
	if (ft_strncmp(e->type, "mandelbrot", 11) == 0)
		mandelbrot(&(e->data), e->lims);
	else if (ft_strncmp(e->type, "julia", 6) == 0)
		julia(e, e->lims);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->data.img, 0, 0);
	mlx_destroy_image(e->mlx, e->data.img);
	return (0);
}

int	key_hook(int boutton, t_info *e)
{
	double	temp;

	if (boutton == 123 || boutton == 124)
	{
		temp = 0.1 * (e->lims.max_x - e->lims.min_x) * -1;
		if (boutton == 124)
			temp *= -1;
		e->lims.max_x += temp;
		e->lims.min_x += temp;
	}
	if (boutton == 125 || boutton == 126)
	{
		temp = 0.1 * (e->lims.max_y - e->lims.min_y) * -1;
		if (boutton == 125)
			temp *= -1;
		e->lims.max_y += temp;
		e->lims.min_y += temp;
	}
	if (boutton == 69)
		e->lims.max_iter += 1;
	if (boutton == 78)
		e->lims.max_iter -= 1;
	return (0);
}

int	mouse_hook(int boutton, int x, int y, t_info *e)
{
	double	a;
	double	b;
	double	temp;

	if (boutton == 5)
	{
		a = x / 1920.0;
		b = y / 1080.0;
		temp = (e->lims.max_x - e->lims.min_x) * a * 0.15;
		e->lims.max_x -= (e->lims.max_x - e->lims.min_x) * (1.0 - a) * 0.15;
		e->lims.min_x += temp;
		temp = (e->lims.max_y - e->lims.min_y) * b * 0.15;
		e->lims.max_y -= (e->lims.max_y - e->lims.min_y) * (1.0 - b) * 0.15;
		e->lims.min_y += temp;
	}
	else if (boutton == 4)
	{
		a = x / 1920.0;
		b = y / 1080.0;
		temp = (e->lims.max_x - e->lims.min_x) * a * 0.15;
		e->lims.max_x += (e->lims.max_x - e->lims.min_x) * (1.0 - a) * 0.15;
		e->lims.min_x -= temp;
		temp = (e->lims.max_y - e->lims.min_y) * b * 0.15;
		e->lims.max_y += (e->lims.max_y - e->lims.min_y) * (1.0 - b) * 0.15;
		e->lims.min_y -= temp;
	}
	return (0);
}


int	loop_hook(t_info *e)
{
	render(e);
	mlx_key_hook(e->mlx_win, &key_hook, e);
	mlx_mouse_hook(e->mlx_win, &mouse_hook, e);
	return (0);
}

 int	main(int argc, char* argv[])
{
	t_info	data;

	if (argc > 1 && (ft_strncmp(argv[1], "mandelbrot", 20) == 0 || ft_strncmp(argv[1], "julia", 6) == 0))
	{
		data = *(t_info *) malloc(sizeof(t_info));
		data.mlx = (void *) malloc(sizeof(void *));
		data.mlx_win = (void *) malloc(sizeof(void *));
		data.mlx = mlx_init();
		data.type = argv[1];
		data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "fract-ol");
		limits_set(&data.lims);
		mlx_loop_hook(data.mlx, &loop_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("%s", "Available commands: mandelbrot, julia");
	return (0);
}
