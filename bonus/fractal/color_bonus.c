/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:02:12 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:35:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_shift_color_tab_left
 *	-------------------------
 *	Shifts the values in the color list for color effects, moving the
 *	values from right to left
 *
 *	data: General data structure
 *
 */

void	ft_shift_color_tab_left(t_data *data)
{
	int	i;
	int	temp;

	i = 1;
	temp = data->color_tab[0];
	data->color_tab[0] = data->color_tab[COLOR_MAX];
	data->color_tab[COLOR_MAX] = temp;
	while (i < COLOR_MAX - 1)
	{
		temp = data->color_tab[i];
		data->color_tab[i] = data->color_tab[i + 1];
		data->color_tab[i + 1] = temp;
		i++;
	}
}

/*
 *	Function: ft_shift_color_tab_right
 *	-------------------------
 *	Shifts the values in the color list for color effects, moving the
 *	values from left to right
 *
 *	data: General data structure
 *
 */

void	ft_shift_color_tab_right(t_data *data)
{
	int	i;
	int	temp;

	i = COLOR_MAX - 1;
	temp = data->color_tab[0];
	data->color_tab[0] = data->color_tab[COLOR_MAX];
	data->color_tab[COLOR_MAX] = temp;
	while (i > 0)
	{
		temp = data->color_tab[i];
		data->color_tab[i] = data->color_tab[i - 1];
		data->color_tab[i - 1] = temp;
		i--;
	}
}
