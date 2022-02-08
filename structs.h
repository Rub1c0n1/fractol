/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:17:19 by dgizzard          #+#    #+#             */
/*   Updated: 2022/02/08 21:17:21 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

typedef struct s_lims {
	double	max_x;
	double	minx;
	double	max_y;
	double	miny;
	double	max_iter;
}			t_lims;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		b_p_p;
	int		l_s;
	int		end;
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