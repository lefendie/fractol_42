/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:21:50 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 11:23:13 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

int	ft_initializer(t_data *data);
int	ft_initialize_data_list(t_data *data);
int	ft_fill_first_data(t_data *data);
int	ft_compute_parameters(int argc, char **argv, t_data *data);

#endif
