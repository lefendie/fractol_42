/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:19:46 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:51:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_listen_mouse_scroll_bonus
 *	-------------------------
 *	Listen for mouse scroll up and down allowing to zoom and shift where
 *	the mouse is
 *
 *	key: Key index hit
 *	x: Current x position of the mouse
 *	y: Current y position of the mouse
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_listen_mouse_scroll_bonus(int key, int x, int y, t_data *data)
{
	if (key == 4 || key == 5)
	{
		if (key == 4)
			ft_zoom_in_positions(data->list_z_r, data->list_z_i, &data->zoom);
		else if (key == 5)
			ft_zoom_out_positions(data->list_z_r, data->list_z_i, &data->zoom);
		if (data->fractal_set != 'I')
		{
			data->x_shift += data->list_z_r[x] * fabs(data->zoom);
			data->y_shift += data->list_z_i[y] * fabs(data->zoom);
		}
		ft_print_image_bonus(data);
		ft_reset_mouse(data);
	}
	return (SUCCESS);
}
