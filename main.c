#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	if (boutton == 53)
		exit(0);
	return (0);
}

t_info limits_set(t_info *data)
{
	if (ft_strncmp(data->type, "mandelbrot", 11) == 0)
	{
		data->lims.max_x = 1;
		data->lims.min_x = -2;
		data->lims.max_y = 1;
		data->lims.min_y = -1;
		data->lims.max_iter = 50;
	}
	else if (ft_strncmp(data->type, "julia", 6) == 0)
	{
		data->lims.max_x = 2;
		data->lims.min_x = -2;
		data->lims.max_y = 1;
		data->lims.min_y = -1;
		data->lims.max_iter = 20;
	}

	return (*data);
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
	t_info	e;

	if (argc > 1 && (ft_strncmp(argv[1], "mandelbrot", 20) == 0 || ft_strncmp(argv[1], "julia", 6) == 0))
	{
		e = *(t_info *)malloc(sizeof(t_info));
		e.mlx = (void *)malloc(sizeof(void *));
		e.mlx_win = (void *)malloc(sizeof(void *));
		e.mlx = mlx_init();
		e.type = argv[1];
		if (argc == 4)
		{
			e.julia_params.c_im = (double)(ft_atoi(argv[2]));
			e.julia_params.c_re = (double)(ft_atoi(argv[3]));
		}
		else
		{
			e.julia_params.c_im = -10;
			e.julia_params.c_re = -10;
		}
		e.mlx_win = mlx_new_window(e.mlx, 1920, 1080, "fract-ol");
		limits_set(&e);
		mlx_loop_hook(e.mlx, &loop_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		printf("%s", "Available commands: mandelbrot, julia");
	return (0);
}
