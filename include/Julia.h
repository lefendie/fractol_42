/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:11:58 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 17:37:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

void	ft_set_pixel_Julia(int x, int y, t_complex *c, t_data *data);
int		ft_get_Julia_color(t_complex *c, t_complex *z);

#endif
