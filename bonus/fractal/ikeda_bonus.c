/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikeda_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:38:12 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:33:22 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_get_ikeda_next_pos
 *	-------------------------
 *	Get the position of the next iteration of the current position
 *	following the sequence for x+1 = 1 + u * (x * cos(t) - y * sin(t))
 *	and y+1 = u * (x * sin(t) + y * cos(t)) with 
 *	t = 0.4 - (6 / (1 + x * x + y * y))
 *
 *	u: Current state for the Ikeda attractor
 *	pos: Position of the current point
 *
 */

void	ft_get_ikeda_next_pos(double u, t_pos *pos)
{
	double	t;
	double	sin_t;
	double	cos_t;
	double	temp_x;
	double	temp_y;

	temp_x = pos->x;
	temp_y = pos->y;
	t = 0.4 - (6 / (1 + (temp_x * temp_x) + (temp_y * temp_y)));
	sin_t = sin(t);
	cos_t = cos(t);
	temp_x = 1 + u * (temp_x * cos_t - temp_y * sin_t);
	temp_y = u * (pos->x * sin_t + temp_y * cos_t);
	pos->x = temp_x;
	pos->y = temp_y;
}

/*
 *	Function: ft_print_ikeda_point
 *	-------------------------
 *	Print the pixel with its color if the point falls in the area of
 *	the window
 *
 *	data: General data structure
 *	color: RGB int value
 *	x: X position of the point
 *	y: Y position of the point
 *
 */

void	ft_print_ikeda_point(t_data *data, int color, double x, double y)
{
	char	*img_line;
	int		t_x;
	int		t_y;

	t_x = ((x * WIN_WIDTH_HALF) / data->zoom)
		- ((data->x_shift * data->zoom) * WIN_WIDTH_HALF);
	t_y = (((y * WIN_HEIGHT_HALF) + WIN_HEIGHT_HALF) / data->zoom)
		- ((data->y_shift * data->zoom) * WIN_HEIGHT_HALF);
	if (t_x > -1 && t_y > -1 && t_x < WIN_WIDTH && t_y < WIN_HEIGHT)
	{
		img_line = data->img->address + t_y * data->img->size_line + t_x * 4;
		*(unsigned int *)img_line = color;
	}
}

/*
 *	Function: ft_set_ikeda_trajectory
 *	-------------------------
 *	Prints all the points for each iteration of the sequence according
 *	the an initial position forming a following of points which look
 *	like a trajectory
 *
 *	prev_pos: initial position of the trajectory
 *	u: Current state for the Ikeda attractor
 *	data: General data structure
 *
 */

void	ft_set_ikeda_trajectory(t_pos *prev_pos, double u, t_data *data)
{
	t_pos	next_pos;
	int		i;

	i = 0;
	next_pos.x = ((prev_pos->x - WIN_WIDTH_HALF)
			/ (double)WIN_WIDTH_HALF);
	next_pos.y = ((prev_pos->y - WIN_HEIGHT_HALF)
			/ (double)WIN_HEIGHT_HALF);
	ft_get_ikeda_next_pos(u, &next_pos);
	while (i < COLOR_MAX)
	{
		ft_get_ikeda_next_pos(u, &next_pos);
		ft_print_ikeda_point(data, data->color_tab[i],
			next_pos.x, next_pos.y);
		prev_pos->x = next_pos.x;
		prev_pos->y = next_pos.y;
		i++;
	}
}
