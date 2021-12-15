/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:35:35 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:57:02 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*error_message;

	error_message = "No parameters\nJ = Julia, M = Mandelbrot\n2 nb for J";
	data = malloc(sizeof(t_data));
	ft_initializer(data);
	if (argc == 1)
		ft_exit_with_error(error_message, 'r');
	if (!data)
		return (FAILURE);
	if (!ft_compute_parameters(argc, argv, data))
		ft_exit_with_error_var("Invalid parameter", argv[1], 'r');
	ft_process(data);
	return (SUCCESS);
}
