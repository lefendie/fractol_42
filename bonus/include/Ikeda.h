/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ikeda.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:08:45 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 11:18:48 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IKEDA_H
# define IKEDA_H

void	ft_get_ikeda_next_pos(double u, t_pos *pos);
void	ft_set_ikeda_trajectory(t_pos *prev_pos, double u, t_data *data);
void	ft_print_ikeda_point(t_data *data, int color, double x, double y);

#endif
