/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:23:33 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:41:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 *	Function: ft_clean_exit_bonus
 *	-------------------------
 *	Allow the clean exit of the program by freeing the allocated 
 *	variables for the bonus part
 *
 *	data: General data structure
 *
 */

void	ft_clean_exit_bonus(t_data *data)
{
	int	i;

	i = 0;
	printf("Closing program...\n");
	free(data->c);
	free(data->list_z_r);
	free(data->list_z_i);
	free(data->color_tab);
	free(data->img);
	free(data->mlx_win);
	free(data->mlx_ptr);
	while (i < data->max_random_list)
	{
		free(data->random_pos[i]);
		i++;
	}
	free(data->random_pos);
	free(data);
	printf("Program Closed\n");
	exit(SUCCESS);
}
