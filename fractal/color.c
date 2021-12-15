/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:56:01 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:23:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_fill_color_tab
 *	-------------------------
 *	Put all the colors available in the range of the spectrum divided by
 *	the maximum number of iteration for the fractal
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_fill_color_tab(t_data *data)
{
	float	color_split;
	int		i;
	int		color_variant;

	i = 0;
	color_variant = COLOR_MAX / 3;
	color_split = 255 / color_variant;
	while (i < COLOR_MAX)
	{
		if (i < color_variant)
			data->color_tab[i] = 0 << 24 | (int)(255 - (i * color_split)) << 16
				| (int)(i * color_split) << 8 | 0;
		else if (color_variant * 2)
			data->color_tab[i] = 0 << 24 | 0 << 16
				| (int)(255 - (i * color_split)) << 8 | (int)(i * color_split);
		else if (COLOR_MAX)
			data ->color_tab[i] = 0 << 24 | (int)(i * color_split) << 16
				| 0 << 8 | (int)(255 - (i * color_split));
		i++;
	}
	return (SUCCESS);
}
