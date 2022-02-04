//
// Created by Deadshot Gizzard on 2/4/22.
//

#ifndef STRUCTS_H

typedef struct s_lims {
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	max_iter;
}			t_lims;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_julia_params {
	double	c_re;
	double	c_im;
}				t_julia_params;

typedef struct s_cmp {
	double	x;
	double	y;
	double	c_re;
	double	c_im;
}				t_cmp;

typedef struct s_info
{
	void			*mlx;
	void			*mlx_win;
	char			*type;
	t_data			data;
	t_lims			lims;
	t_julia_params	julia_params;
}				t_info;

#endif //STRUCTS_H