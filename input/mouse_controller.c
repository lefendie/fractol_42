/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:03:58 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:20:56 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_listen_mouse_scroll
 *	-------------------------
 *	Listen for mouse scroll up and down allowing to zoom
 *
 *	key: Key index hit
 *	x: Current x position of the mouse
 *	y: Current y position of the mouse
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_listen_mouse_scroll(int key, int x, int y, t_data *data)
{
	x = 1;
	y = 1;
	if (key == 4)
		ft_zoom_in_positions(data->list_z_r, data->list_z_i, &data->zoom);
	else if (key == 5)
		ft_zoom_out_positions(data->list_z_r, data->list_z_i, &data->zoom);
	ft_print_image(data);
	return (SUCCESS);
}

/*
 *	Function: ft_reset_mouse
 *	-------------------------
 *	Reset the position of the mouse to the center of the window
 *
 *	data: General data structure
 *
 */

void	ft_reset_mouse(t_data *data)
{
	mlx_mouse_move(data->mlx_ptr, data->mlx_win,
		WIN_WIDTH_HALF, WIN_HEIGHT_HALF);
}
