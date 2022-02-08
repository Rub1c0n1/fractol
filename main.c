/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:25 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:25 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_s + x * (data->b_p_p / 8));
	*(unsigned int *)dst = color;
}

t_info	limits_set(t_info *data)
{
	if (ft_strncmp(data->type, "mandelbrot", 11) == 0)
	{
		data->lims.max_x = 1;
		data->lims.minx = -2;
		data->lims.max_y = 1;
		data->lims.miny = -1;
		data->lims.max_iter = 50;
	}
	else if (ft_strncmp(data->type, "julia", 6) == 0)
	{
		data->lims.max_x = 2;
		data->lims.minx = -2;
		data->lims.max_y = 1;
		data->lims.miny = -1;
		data->lims.max_iter = 20;
	}
	return (*data);
}

int	main(int argc, char*argv[])
{
	t_info	e;

	if (argc > 1 && (ft_strncmp(argv[1], "mandelbrot", 20) == 0
			|| ft_strncmp(argv[1], "julia", 6) == 0))
	{
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
