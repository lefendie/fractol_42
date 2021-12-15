/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:14:46 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:49:58 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_process_bonus
 *	-------------------------
 *	Main function for the general process of fractol with the bonus part
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_process_bonus(t_data *data)
{
	ft_print_image_bonus(data);
	mlx_hook(data->mlx_win, 4, 1L << 2, ft_listen_mouse_scroll_bonus, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_listen_key_pressed, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_listen_key_just_pressed_bonus, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}
