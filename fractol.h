/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:29 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:30 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include "structs.h"
# include "libmlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

int     destroy_window(int keycode, t_info *e);
void	print_pixel(int iteration, t_info *e, double col, double row);
void	julia_formule(t_cmp *cmp, t_lims *lims, double *x_new, int *iteration);
int		key_hook(int button, t_info *e);
int		mouse_hook(int button, int x, int y, t_info *e);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_info	limits_set(t_info *data);
void	mandelbrot(t_info *e, t_lims lims, double col, double row);
void	julia(t_info *e, t_lims lims, double row, double col);
int		render(t_info *e);
int		loop_hook(t_info *e);
int		main(int argc, char*argv[]);

#endif //FRACTOL_H