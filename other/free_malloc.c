/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:16:55 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:10:11 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *	Function: ft_clean_exit
 *	-------------------------
 *	Allow the clean exit of the program by freeing the allocated 
 *	variables
 *
 *	data: General data structure
 *
 */

void	ft_clean_exit(t_data *data)
{
	printf("Closing program...\n");
	free(data->c);
	free(data->list_z_r);
	free(data->list_z_i);
	free(data->color_tab);
	free(data->img);
	free(data->mlx_win);
	free(data->mlx_ptr);
	free(data);
	printf("Program Closed\n");
	exit(SUCCESS);
}
