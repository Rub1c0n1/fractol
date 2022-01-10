#include "MLX/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cock {
	double	re;
	double	ij;
	double	ntekre;
	double	ntekij;
	double	mod;
}				t_cock;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

doub

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_cock	mand[1920][1080];
	for (int i = 0; i < 1920; i++)
	{
		for (int j = 0; j < 1080; j++)
		{
			mand[i][j]->ntekre = 0;
			mand[i][j]->ntekij = 0;
			mand[i][j]->mod = 0;
			mand[i][j]->re = (i - 1280) / 640;
			mand[i][j]->ij = (j - 540) / 540;
		}
	}

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}