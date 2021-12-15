/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controller_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:16:39 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:39:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_listen_key_just_pressed_bonus
 *	-------------------------
 *	Listener for clean exit of shift to move around the fractal
 *
 *	key: Key index hit
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_listen_key_just_pressed_bonus(int key, t_data *data)
{
	if (key == 65362)
		data->y_shift -= 0.1 / data->zoom;
	else if (key == 65361)
		data->x_shift -= 0.1 / data->zoom;
	else if (key == 65364)
		data->y_shift += 0.1 / data->zoom;
	else if (key == 65363)
		data->x_shift += 0.1 / data->zoom;
	else if (key == 65307)
		ft_clean_exit_bonus(data);
	ft_print_image_bonus(data);
	return (SUCCESS);
}

/*
 *	Function: ft_listen_key_pressed
 *	-------------------------
 *	Listener for color shifting or changing of the Ikeda state
 *
 *	key: Key index hit
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_listen_key_pressed(int key, t_data *data)
{
	if (key == 'j')
		data->u += 0.01;
	else if (key == 'k')
		data->u -= 0.01;
	else if (key == 'l')
		ft_shift_color_tab_right(data);
	else if (key == 'h')
		ft_shift_color_tab_left(data);
	ft_print_image_bonus(data);
	return (SUCCESS);
}
