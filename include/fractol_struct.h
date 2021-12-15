/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:49:07 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 13:38:40 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct s_complex
{
	double	r;
	double	i;
}							t_complex;

typedef struct s_pos
{
	double	x;
	double	y;
}							t_pos;

typedef struct s_img_data
{
	void	*self;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}								t_img_data;

typedef struct s_data
{
	t_img_data	*img;
	t_complex	*c;
	double		x_shift;
	double		y_shift;
	double		*list_z_r;
	double		*list_z_i;
	double		u;
	float		zoom;
	t_pos		**random_pos;
	void		*mlx_ptr;
	void		*mlx_win;
	char		fractal_set;
	int			*color_tab;
	int			max_random_list;
}							t_data;

#endif
