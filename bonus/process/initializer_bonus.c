/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:38:12 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:48:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_initialize_random_pos
 *	-------------------------
 *	Allocate and fills the random pos list of data
 *
 *	data: General data structure
 *	random_nb_count: number of random positions
 *
 *	Returns: Success state
 */

int	ft_initialize_random_pos(t_data *data, int random_nb_count)
{
	int	i;

	i = 0;
	data->random_pos = malloc(sizeof(t_pos *) * random_nb_count);
	if (!data->random_pos)
		return (FAILURE);
	while (i < random_nb_count)
	{
		data->random_pos[i] = malloc(sizeof(t_pos));
		if (!data->random_pos[i])
			return (FAILURE);
		i++;
	}
	ft_fill_random_pos_list(data->random_pos, random_nb_count);
	data->max_random_list = random_nb_count;
	return (SUCCESS);
}

/*
 *	Function: ft_fill_random_pos_list
 *	-------------------------
 *	Fills the random pos list with random x and y which size is defined by
 *	a parameter in the executable
 *
 *	random_pos: List of random position
 *	nb: Number of random position
 *
 */

void	ft_fill_random_pos_list(t_pos **random_pos, int nb)
{
	int	i;
	int	*temp_list_y;
	int	*temp_list_x;

	temp_list_x = ft_get_random_range(0, WIN_WIDTH, nb);
	temp_list_y = ft_get_random_range(0, WIN_HEIGHT, nb);
	i = 0;
	while (i < nb)
	{
		random_pos[i]->x = temp_list_x[i];
		random_pos[i]->y = temp_list_y[i];
		i++;
	}
	free(temp_list_x);
	free(temp_list_y);
}

/*
 *	Function: ft_compute_parameters_bonus
 *	-------------------------
 *	Use the parameters from the executable and put the values in
 *	data for the bonus part
 *
 *	argc: Number of parameters from executable
 *	argv: Parameters from executable
 *	data: General data structure
 *
 *	Returns: Success state
 */

int	ft_compute_parameters_bonus(int argc, char **argv, t_data *data)
{
	if (ft_compute_parameters(argc, argv, data))
		return (SUCCESS);
	if (*argv[1] == 'I')
	{
		data->fractal_set = 'I';
		if (argc != 4 )
			ft_exit_with_error("Ikeda needs 2 numbers", 'r');
		if (!ft_isdbl(argv[2]))
			ft_exit_with_error("U parameter number not a double", 'r');
		if (!ft_isint(argv[3]))
			ft_exit_with_error("Number of points not an integer", 'r');
		data->u = ft_atoi_dbl(argv[2]);
		ft_initialize_random_pos(data, ft_atoi(argv[3]));
	}
	else
		return (FAILURE);
	return (SUCCESS);
}
