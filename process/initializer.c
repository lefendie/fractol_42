/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:17:50 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:21:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_initializer
 *	-------------------------
 *	Allocate and initialize general data like the window or
 *	the precomputed position values
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initializer(t_data *data)
{
	void	*mlx_ptr;
	void	*mlx_win;

	printf("Connection to mlx\n");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (FAILURE);
	printf("Window creation\n");
	mlx_win = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!mlx_win)
		return (FAILURE);
	data->mlx_ptr = mlx_ptr;
	data->mlx_win = mlx_win;
	data->img = malloc(sizeof(t_img_data));
	if (!data->img)
		return (FAILURE);
	data->c = malloc(sizeof(t_complex));
	if (!data->c)
		return (FAILURE);
	ft_initialize_data_list(data);
	ft_fill_first_data(data);
	return (SUCCESS);
}

/*
 *	Function: ft_initialize_data_list
 *	-------------------------
 *	Allocate the color list according to the number of iteration and
 *	allocate the precomputed position list
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_initialize_data_list(t_data *data)
{
	data->color_tab = malloc(sizeof(int) * (COLOR_MAX + 1));
	if (!data->color_tab)
		return (FAILURE);
	data->list_z_i = malloc(sizeof(double) * WIN_HEIGHT + 1);
	if (!data->list_z_i)
		return (FAILURE);
	data->list_z_r = malloc(sizeof(double) * WIN_WIDTH + 1);
	if (!data->list_z_r)
		return (FAILURE);
	return (SUCCESS);
}

/*
 *	Function: ft_fill_first_data
 *	-------------------------
 *	Fill general data to data that is shift, zoom, color list and
 *	precomputed position list
 *
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_fill_first_data(t_data *data)
{
	data->zoom = 1;
	data->y_shift = 0;
	data->x_shift = 0;
	ft_fill_color_tab(data);
	ft_fill_converted_positions_tab(data);
	return (SUCCESS);
}

/*
 *	Function: ft_compute_parameters
 *	-------------------------
 *	Use the parameters from the executable and put the values in
 *	data
 *
 *	argc: Number of parameters from executable
 *	argv: Parameters from executable
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_compute_parameters(int argc, char **argv, t_data *data)
{
	if (*argv[1] == 'J')
	{
		data->fractal_set = 'J';
		if (argc != 4 )
			ft_exit_with_error("Julia needs 2 numbers", 'r');
		if (!ft_isdbl(argv[2]))
			ft_exit_with_error("Real number not a double", 'r');
		if (!ft_isdbl(argv[3]))
			ft_exit_with_error("Imaginary number not a double", 'r');
		data->c->r = ft_atoi_dbl(argv[2]);
		data->c->i = ft_atoi_dbl(argv[3]);
		if (data->c->r > 1 || data->c->r < -1)
			ft_exit_with_error("Real number not in range [-1;1]", 'r');
		if (data->c->i > 1 || data->c->i < -1)
			ft_exit_with_error("Imaginary  number not in range [-1;1]", 'r');
	}
	else if (*argv[1] == 'M')
		data->fractal_set = 'M';
	else
		return (FAILURE);
	return (SUCCESS);
}
