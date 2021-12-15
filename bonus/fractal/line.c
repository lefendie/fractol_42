/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:02:29 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:42:50 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * #include "fractol_bonus.h"

void ft_line_low_slope(t_pos *p1, t_pos *p2, int color, t_data *data)
{
	double D;
	double d_x;
	double d_y;
	int y_increment;
	int x_increment;

	d_x = p2->x-p1->x;
	d_y = p2->y-p1->y;
	y_increment = 1;
	x_increment = 1;
	if (p1->y > p2->y)
	{
		y_increment = -1;
		d_y = -d_y;
	}
	if (p1->x > p2->x)
		x_increment = -1;
	D = 2 * d_y - d_x;
	while (p1->x != p2->x)
	{
		if (D > 0)
		{
			p1->y+=y_increment;
			D = D + 2 *( d_y - d_x);
		}
		D = D + 2 * d_y;
		p1->x+=x_increment;
		if (p1->x > -1 && p1->y > -1 && p1->x < WIN_WIDTH && p1->y < WIN_HEIGHT)
		{
			*(unsigned int *)(data->img->address
			+ ((int)p1->y * data->img->size_line) + (int)p1->x * 4) = color;
		}
	}
}
void ft_line_high_slope(t_pos *p1, t_pos *p2, int color, t_data *data)
{
	double D;
	double d_x;
	double d_y;
	int x_increment;
	int y_increment;

	d_x = p2->x-p1->x;
	d_y = p2->y-p1->y;
	x_increment = 1;
	y_increment = 1;
	if (p1->x > p2->x)
	{
		x_increment = -1;
		d_x = -d_x;
	}
	if (p1->y > p2->y)
		y_increment = -1;
	D = 2 * d_x - d_y;
	while (p1->y != p2->y)
	{
		if (D > 0)
		{
			p1->x+=x_increment;
			D = D + 2 *(d_x - d_y);
		}
		D = D + 2 * d_x;
		p1->y+=y_increment;
		if (p1->x > -1 && p1->y > -1 && p1->x < WIN_WIDTH && p1->y < WIN_HEIGHT)
		{
			*(unsigned int *)(data->img->address
+ ((int)p1->y * data->img->size_line) + (int)p1->x * 4) = color;
		}
	}
}

void ft_join_pos_color(t_pos *p1, t_pos *p2, int color, t_data *data)
{
	if (fabs(p2->y - p1->y) < fabs(p2->x- p1->x))
	{
		if (p1->x > p2->x)
			ft_line_low_slope(p2, p1, color, data);
		else
			ft_line_low_slope(p1, p2, color, data);
	}
	else
	{
		if (p1->y > p2->y)
			ft_line_high_slope(p2, p1, color, data);
		else
			ft_line_high_slope(p1, p2, color, data);
	}	
}

void	ft_join_ikeda_points(t_pos *prev_pos,
		t_pos *next_pos, int color, t_data *data)
{
	t_pos temp_pos1;
	t_pos temp_pos2;

	temp_pos1.x =  (prev_pos->x * WIN_WIDTH_HALF);
	temp_pos1.y = ((prev_pos->y * WIN_HEIGHT_HALF) + WIN_HEIGHT_HALF);
	temp_pos2.x =  (next_pos->x * WIN_WIDTH_HALF);
	temp_pos2.y =((next_pos->y * WIN_HEIGHT_HALF) + WIN_HEIGHT_HALF);
	ft_join_pos_color(&temp_pos1, &temp_pos2, color, data);
}
*/
