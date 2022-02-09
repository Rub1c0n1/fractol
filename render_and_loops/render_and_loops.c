/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_loops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:36 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:36 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	for_mlx_get_data(t_data *data, char**addr, void *img)
{
	*addr = mlx_get_data_addr(img, &(data->b_p_p), &(data->l_s), &(data->end));
}

int	destroy_window(int keycode, t_info *e)
{
	mlx_destroy_window(e->mlx, e->mlx_win);
	return (0);
}

int	render(t_info *e)
{
	e->data.img = mlx_new_image(e->mlx, 1920, 1080);
	for_mlx_get_data(&e->data, &(e->data.addr), e->data.img);
	if (ft_strncmp(e->type, "mandelbrot", 11) == 0)
		mandelbrot(e, e->lims, 0, 0);
	else if (ft_strncmp(e->type, "julia", 6) == 0)
		julia(e, e->lims, 0, 0);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->data.img, 0, 0);
	mlx_destroy_image(e->mlx, e->data.img);
	return (0);
}

int	loop_hook(t_info *e)
{
	render(e);
	mlx_hook(e->mlx_win, 2, 1L<<0, destroy_window, &e);
	mlx_key_hook(e->mlx_win, &key_hook, e);
	mlx_mouse_hook(e->mlx_win, &mouse_hook, e);
	return (0);
}
