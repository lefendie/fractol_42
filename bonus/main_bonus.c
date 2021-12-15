/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:35:35 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 13:58:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	data->max_random_list = 0;
	if (argc == 1)
		ft_exit_with_error("No parameters\nJ = Julia, M = Mandelbrot\n2 nb for J",
			'r');
	ft_initializer(data);
	if (!ft_compute_parameters_bonus(argc, argv, data))
		ft_exit_with_error_var("Invalid parameter", argv[1], 'r');
	ft_process_bonus(data);
	return (SUCCESS);
}
