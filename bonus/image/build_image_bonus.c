/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:16:12 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:36:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_print_image_bonus
 *	-------------------------
 *	Make the image and prints it inside the window for the bonus part
 *
 *	data: General data structure where the map variable is located
 *
 *	Returns: Success state
 */

int	ft_print_image_bonus(t_data *data)
{
	ft_create_new_image(data);
	if (data->fractal_set == 'J')
		ft_build_image_Julia(data);
	else if (data->fractal_set == 'M')
		ft_build_image_Mandelbrot(data);
	else if (data->fractal_set == 'I')
		ft_build_image_Ikeda(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->self,
		0, 0);
	return (SUCCESS);
}

/*
 *	Function: ft_build_image_Ikeda
 *	-------------------------
 *	Fills the created image with a Ikeda attractor
 *
 *	data: General data structure 
 *
 */

void	ft_build_image_Ikeda(t_data *data)
{
	t_pos	prev_pos;
	int		max_random_list;
	int		i;

	i = 0;
	max_random_list = data->max_random_list;
	while (i < max_random_list)
	{
		prev_pos.x = data->random_pos[i]->x;
		prev_pos.y = data->random_pos[i]->y;
		ft_set_ikeda_trajectory(&prev_pos, data->u, data);
		i++;
	}
}
