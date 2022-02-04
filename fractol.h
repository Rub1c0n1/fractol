//
// Created by Deadshot Gizzard on 1/21/22.
//
#ifndef FRACTOL_H

# include "structs.h"
# include "libmlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int boutton, t_info *e);
t_info	limits_set(t_info *data);
void	mandelbrot(t_data *data, t_lims lims);
void	julia(t_info *e, t_lims lims);
int		render(t_info *e);
int		mouse_hook(int boutton, int x, int y, t_info *e);
int		loop_hook(t_info *e);
int		main(int argc, char*argv[]);

#endif //FRACTOL_H