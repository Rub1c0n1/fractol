/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:42 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:42 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	arrows_control(int boutton, t_info *e, double temp)
{
	if (boutton == 123 || boutton == 124)
	{
		temp = 0.1 * (e->lims.max_x - e->lims.minx) * -1;
		if (boutton == 124)
			temp *= -1;
		e->lims.max_x += temp;
		e->lims.minx += temp;
	}
	if (boutton == 125 || boutton == 126)
	{
		temp = 0.1 * (e->lims.max_y - e->lims.miny) * -1;
		if (boutton == 125)
			temp *= -1;
		e->lims.max_y += temp;
		e->lims.miny += temp;
	}
}

int	key_hook(int boutton, t_info *e)
{
	double	temp;

	arrows_control(boutton, e, temp);
	if (boutton == 69)
		e->lims.max_iter += 1;
	if (boutton == 78)
		e->lims.max_iter -= 1;
	if (boutton == 53)
	{
		mlx_clear_window(e->mlx, e->mlx_win);
		exit(0);
	}
	return (0);
}

void	wheel_up(t_info *e, double temp, double a, double b)
{
	temp = (e->lims.max_x - e->lims.minx) * a * 0.15;
	e->lims.max_x -= (e->lims.max_x - e->lims.minx) * (1.0 - a) * 0.15;
	e->lims.minx += temp;
	temp = (e->lims.max_y - e->lims.miny) * b * 0.15;
	e->lims.max_y -= (e->lims.max_y - e->lims.miny) * (1.0 - b) * 0.15;
	e->lims.miny += temp;
}

void	wheel_down(t_info *e, double temp, double a, double b)
{
	temp = (e->lims.max_x - e->lims.minx) * a * 0.15;
	e->lims.max_x += (e->lims.max_x - e->lims.minx) * (1.0 - a) * 0.15;
	e->lims.minx -= temp;
	temp = (e->lims.max_y - e->lims.miny) * b * 0.15;
	e->lims.max_y += (e->lims.max_y - e->lims.miny) * (1.0 - b) * 0.15;
	e->lims.miny -= temp;
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
		wheel_up(e, temp, a, b);
	}
	else if (boutton == 4)
	{
		a = x / 1920.0;
		b = y / 1080.0;
		wheel_down(e, temp, a, b);
	}
	return (0);
}
