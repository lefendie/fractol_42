/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:00:52 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 13:37:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_BONUS_H
# define INITIALIZER_BONUS_H

void	ft_fill_random_pos_list(t_pos **random_pos, int nb);
int		ft_initialize_random_pos(t_data *data, int random_nb_count);
int		ft_compute_parameters_bonus(int argc, char **argv, t_data *data);

#endif
