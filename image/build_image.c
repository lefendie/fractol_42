/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:03:07 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:11:55 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_create_new_image
 *	-------------------------
 *	Creates a new image from mlx and gives it to data
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_create_new_image(t_data *data)
{
	t_img_data	*img;

	img = data->img;
	img->self = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(img->self, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (SUCCESS);
}

/*
 *	Function: ft_build_image_Julia
 *	-------------------------
 *	Fills the created image with a Julia fractal
 *
 *	data: General data structure 
 *
 */

void	ft_build_image_Julia(t_data *data)
{
	char	*img_line_sav;
	int		y;
	int		x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		img_line_sav = data->img->address;
		while (x < WIN_WIDTH)
		{
			ft_set_pixel_Julia(x, y, data->c, data);
			x++;
			if (x != WIN_WIDTH)
				data->img->address += 4;
		}
		data->img->address = img_line_sav;
		y++;
		if (y != WIN_HEIGHT)
			data->img->address += data->img->size_line;
	}
}

/*
 *	Function: ft_build_image_Mandelbrot
 *	-------------------------
 *	Fills the created image with a Mandelbrot fractal
 *
 *	data: General data structure 
 *
 */

void	ft_build_image_Mandelbrot(t_data *data)
{
	char	*img_line_sav;
	int		y;
	int		x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		img_line_sav = data->img->address;
		while (x < WIN_WIDTH)
		{
			ft_set_pixel_Mandelbrot(x, y, data->c, data);
			x++;
			if (x != WIN_WIDTH)
				data->img->address += 4;
		}
		data->img->address = img_line_sav;
		y++;
		if (y != WIN_HEIGHT)
			data->img->address += data->img->size_line;
	}
}

/*
 *	Function: ft_print_image
 *	-------------------------
 *	Make the image and prints it inside the window
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_print_image(t_data *data)
{
	ft_create_new_image(data);
	if (data->fractal_set == 'J')
		ft_build_image_Julia(data);
	else if (data->fractal_set == 'M')
		ft_build_image_Mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->self,
		0, 0);
	return (SUCCESS);
}

/*
 *	Function: ft_get_color_from_rgb
 *	-------------------------
 *	Simplify the conversion from a string color to a rgb formated int color
 *
 *	char_rgb: String that contains a color
 *
 *	Returns: Color in int format
 */

int	ft_get_color_from_rgb(char *char_rgb)
{
	if (*char_rgb)
		return ((int)*(char_rgb + 3) << 24 | (int)*(char_rgb + 2) << 16
			| (int)*(char_rgb + 1) << 8 | (int)*(char_rgb));
	return (0);
}
