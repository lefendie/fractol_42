/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:51:57 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:04:38 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_get_Julia_color
 *	-------------------------
 *	Get the color for the sequence z = z*z + c with the first value
 *	z = z->x + z->y. This sequence is iterated until it gives a magnitude 
 *	inferior to 2.
 *	If the magnitude is superior to 2, it is not in the Julia 
 *	set with parameter c
 *	For optimization reasons, the magnitude is not square rooted and so
 *	we change the magnitude to be tested inferior to 4
 *
 *	c: Value that defines the shape of the Julia set
 *	z: Values to be computed
 *
 *	Returns: color index to print
 */

int	ft_get_Julia_color(t_complex *c, t_complex *z)
{
	double	double_z_r;
	double	double_z_i;
	double	old_r;
	int		color;

	color = 0;
	double_z_i = z->i * z->i;
	double_z_r = z->r * z->r;
	while (double_z_r + double_z_i < 4 && color < COLOR_MAX)
	{	
		old_r = z->r;
		z->r = (double_z_r - double_z_i) + c->r;
		z->i = z->i * old_r * 2 + c->i;
		color++;
		double_z_i = z->i * z->i;
		double_z_r = z->r * z->r;
	}
	return (color);
}

/*
 *	Function: ft_set_pixel_Julia
 *	-------------------------
 *	Get the color from the iteration of the Julia sequence and 
 *	print the color from a coordinate
 *
 *	x: Current x pixel coordinate
 *	y: Current y pixel coordinate
 *	c: Value that defines the shape of the Julia set
 *	data: General data structure
 *
 */

void	ft_set_pixel_Julia(int x, int y, t_complex *c, t_data *data)
{
	t_complex	z;
	char		*img_line;
	int			color;

	img_line = data->img->address;
	z.r = data->list_z_r[x] + data->x_shift;
	z.i = data->list_z_i[y] + data->y_shift;
	color = ft_get_Julia_color(c, &z);
	color = data->color_tab[color];
	*(unsigned int *)img_line = color;
}
