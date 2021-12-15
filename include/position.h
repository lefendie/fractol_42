/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:44:21 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 21:19:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

int	ft_fill_converted_positions_tab(t_data *data);
int	ft_apply_zoom_to_converted_positions(t_data *data);
int	ft_zoom_in_positions(double *list_z_r, double *list_z_i, float *zoom);
int	ft_zoom_out_positions(double *list_z_r, double *list_z_i, float *zoom);

#endif
