//
// Created by Deadshot Gizzard on 1/21/22.
//

#ifndef FRACTOL_H
#define FRACTOL_H

#include "libmlx/mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "libft/libft.h"

typedef struct s_lims {
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	max_iter;
	char	type;
}			t_lims;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_cmp {
	double x;
	double y;
	double c_re;
	double c_im;
}				t_cmp;

typedef struct s_info
{
	int 	iteration;
	int		max_iter;
	void	*mlx;
	void	*mlx_win;
	char	*type;
	t_data	data;
}				t_info;

char	*pointer_to_hex(size_t num);

#endif //FRACTOL_H
