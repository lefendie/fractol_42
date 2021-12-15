/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:16:39 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:06:10 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_listen_key_just_pressed
 *	-------------------------
 *	Listener for the Esc key allowing for clean exit
 *
 *	key: Key index hit
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_listen_key_just_pressed(int key, t_data *data)
{
	if (key == 65307)
		ft_clean_exit(data);
	return (SUCCESS);
}
