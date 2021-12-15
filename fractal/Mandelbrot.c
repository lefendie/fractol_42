/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:18:22 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:04:56 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_get_Mandelbrot_color
 *	-------------------------
 *	Get the color from the sequence z = z*z + c
 *	The difference with the Julia set is that the z start with 
 *	z->r = 0 and z->i = 0 and that c correspond to the current
 *	pixel coordinates. This allows the construction of every
 *	Julia set within one fractal
 *
 *	c: Value that defines the shape of the Julia set
 *	z: Values to be computed
 *
 *	Returns: color index to print
 */

int	ft_get_Mandelbrot_color(t_complex *c, t_complex *z)
{
	double	double_z_r;
	double	double_z_i;
	double	old_r;
	int		color;

	color = 0;
	double_z_i = z->i * z->i;
	double_z_r = z->r * z->r;
	while ((double_z_r + double_z_i) < 4 && color < COLOR_MAX)
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
 *	Function: ft_set_pixel_Mandelbrot
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

void	ft_set_pixel_Mandelbrot(int x, int y, t_complex *c, t_data *data)
{
	t_complex	z;
	char		*img_line;
	int			color;

	img_line = data->img->address;
	z.r = 0;
	z.i = 0;
	data->c->r = data->list_z_r[x] + data->x_shift;
	data->c->i = data->list_z_i[y] + data->y_shift;
	color = ft_get_Mandelbrot_color(c, &z);
	color = data->color_tab[color];
	*(unsigned int *)img_line = color;
}
