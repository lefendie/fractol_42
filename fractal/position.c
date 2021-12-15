/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:29:36 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:32:28 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_fill_converted_positions_tab
 *	-------------------------
 *	Fills the list of real and imaginary numbers with x corresponding to 
 *	z and y corresponding to i. {x;y} must be reduced to values in range
 *	of [-1;1]
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_fill_converted_positions_tab(t_data *data)
{
	int	i;

	i = 0;
	while (i <= WIN_WIDTH)
	{
		data->list_z_r[i] = ((i - WIN_WIDTH_HALF)
				/ (double)WIN_WIDTH_HALF) / data->zoom * 3;
		i++;
	}
	i = 0;
	while (i <= WIN_HEIGHT)
	{
		data->list_z_i[i] = ((i - WIN_HEIGHT_HALF)
				/ (double)WIN_HEIGHT_HALF) / data->zoom * 3;
		i++;
	}
	return (SUCCESS);
}

/*
 *	Function: ft_zoom_in_positions
 *	-------------------------
 *	Modify the zoom of data and apply it to the list of real and
 *	imaginary numbers of data by zooming in
 *
 *	list_z_r: List of real values
 *	list_z_i: List of imaginary values 
 *	zoom: Pointer to the zoom of data
 *
 *	Returns: Success state
 */

int	ft_zoom_in_positions(double *list_z_r, double *list_z_i, float *zoom)
{
	int	i;

	i = 0;
	(*zoom)++;
	if (*zoom == 0)
		(*zoom) += 1;
	while (i <= WIN_WIDTH)
	{
		list_z_r[i] /= *zoom;
		i++;
	}
	i = 0;
	while (i <= WIN_HEIGHT)
	{
		list_z_i[i] /= *zoom;
		i++;
	}
	return (SUCCESS);
}

/*
 *	Function: ft_zoom_out_positions
 *	-------------------------
 *	Modify the zoom of data and apply it to the list of real and
 *	imaginary numbers of data by zooming out
 *
 *	list_z_r: List of real values
 *	list_z_i: List of imaginary values 
 *	zoom: Pointer to the zoom of data
 *
 *	Returns: Success state
 */

int	ft_zoom_out_positions(double *list_z_r, double *list_z_i, float *zoom)
{
	int	i;
	int	zoom_temp;

	i = 0;
	(*zoom)--;
	if (*zoom < 1)
		*zoom = 1;
	zoom_temp = fabs(*zoom);
	while (i <= WIN_WIDTH)
	{
		list_z_r[i] += list_z_r[i] * zoom_temp;
		i++;
	}
	i = 0;
	while (i <= WIN_HEIGHT)
	{
		list_z_i[i] += list_z_i[i] * zoom_temp;
		i++;
	}
	return (SUCCESS);
}
