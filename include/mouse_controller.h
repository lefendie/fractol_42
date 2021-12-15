/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:05:02 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:15:50 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_CONTROLLER_H
# define MOUSE_CONTROLLER_H

void	ft_reset_mouse(t_data *data);
int		ft_listen_mouse_scroll(int key, int x, int y, t_data *data);
int		ft_listen_mouse_release_control(int key, int x, int y, t_data *data);

#endif
