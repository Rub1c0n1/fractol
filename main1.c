#include "libmlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double	max_x = 2;
double	min_x = -2;
double	max_y = 1;
double	min_y = -1;
double	max_iter = 50;
char	type;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_env
{
	void	*win;
	void	*mlx;
	t_data	data;
}				t_env;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	refresher(t_data *data)
{
	double	temp;
	double	re;
	double	ij;
	double	cre;
	double	cij;
	double	iter;

	for (int i = 0; i < 1920; i++)
	{
		cre = min_x + (double)i / 1920 * (max_x - min_x);
		for (int j = 0; j < 1080; j++)
		{
			re = 0;
			ij = 0;
			cij = min_y + (double)j / 1080 * (max_y - min_y);
			iter = 0;
			while (re * re + ij * ij < 4 && iter < max_iter)
			{
				temp = re * re - ij * ij + cre;
				ij = 2 * re * ij + cij;
				re = temp;
				iter++;
			}
			if (iter < max_iter)
				my_mlx_pixel_put(data, i, j, iter * 0x081648);
			else
				my_mlx_pixel_put(data, i, j, 0x000);
		}
	}
}

void	refresher_j(void *win, t_data *data)
{
	double	temp;
	double	re;
	double	ij;
	int		cx;
	int		cy;
	double	cre;
	double	cij;
	double	iter;

	mlx_mouse_get_pos(win, &cx, &cy);
	for (int i = 0; i < 1920; i++)
	{
		cre = min_x + (double)cx / 1920 * (max_x - min_x);
		for (int j = 0; j < 1080; j++)
		{
			cij = min_y + (double)cy / 1080 * (max_y - min_y);
			re = min_x + (double)i / 1920 * (max_x - min_x);
			ij = min_y + (double)j / 1080 * (max_y - min_y);
			iter = 0;
			while (re * re + ij * ij < 4 && iter < max_iter)
			{
				temp = re * re - ij * ij + cre;
				ij = 2 * re * ij + cij;
				re = temp;
				iter++;
			}
			if (iter < max_iter)
				my_mlx_pixel_put(data, i, j, iter * 0x081648);
			else
				my_mlx_pixel_put(data, i, j, 0x000);
		}
	}
}

int	render(t_env *e)
{
	e->data.img = mlx_new_image(e->mlx, 1920, 1080);
	e->data.addr = mlx_get_data_addr(e->data.img, &(e->data.bits_per_pixel), &(e->data.line_length), &(e->data.endian));
	if (type == 'm')
		refresher(&(e->data));
	else if (type == 'j')
		refresher_j(e->win, &(e->data));
	mlx_put_image_to_window(e->mlx, e->win, e->data.img, 0, 0);
	mlx_destroy_image(e->mlx, e->data.img);
	return (0);
}

int	key_hook(int boutton, t_env *e)
{
	double	temp;

	if (boutton == 123 || boutton == 124)
	{
		temp = 0.1 * (max_x - min_x) * -1;
		if (boutton == 124)
			temp *= -1;
		max_x += temp;
		min_x += temp;
	}
	if (boutton == 125 || boutton == 126)
	{
		temp = 0.1 * (max_y - min_y) * -1;
		if (boutton == 125)
			temp *= -1;
		max_y += temp;
		min_y += temp;
	}
	return (0);
}

int	mouse_hook(int boutton, int x, int y, t_env *e)
{
	double	a;
	double	b;
	double	temp;

	if (boutton == 5)
	{
		a = x / 1920.0;
		b = y / 1080.0;
		temp = (max_x - min_x) * a * 0.15;
		max_x -= (max_x - min_x) * (1.0 - a) * 0.15;
		min_x += temp;
		temp = (max_y - min_y) * b * 0.15;
		max_y -= (max_y - min_y) * (1.0 - b) * 0.15;
		min_y += temp;
		max_iter *= 1.03;
		printf("%f, %f, %f, %f\n", min_x, max_x, min_y, max_y);
	}
	else if (boutton == 4)
	{
		a = x / 1920.0;
		b = y / 1080.0;
		temp = (max_x - min_x) * a * 0.15;
		max_x += (max_x - min_x) * (1.0 - a) * 0.15;
		min_x -= temp;
		temp = (max_y - min_y) * b * 0.15;
		max_y += (max_y - min_y) * (1.0 - b) * 0.15;
		min_y -= temp;
		max_iter /= 1.03;
		printf("%f, %f, %f, %f\n", min_x, max_x, min_y, max_y);
	}
	return (0);
}

int	loop_hook(t_env *e)
{
	render(e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_mouse_hook(e->win, &mouse_hook, e);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	argc = 0;
	e = *(t_env *)malloc(sizeof(t_env));
	e.mlx = (void *)malloc(sizeof(void *));
	e.win = (void *)malloc(sizeof(void *));
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "Hello world!");
	type = argv[1][0];
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}