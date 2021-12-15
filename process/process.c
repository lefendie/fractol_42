/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:00:00 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:21:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_process
 *	-------------------------
 *	Main function for the general process of fractol
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_process(t_data *data)
{
	ft_print_image(data);
	mlx_hook(data->mlx_win, 4, 1L << 2, ft_listen_mouse_scroll, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_listen_key_just_pressed, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}
