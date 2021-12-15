/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:23:07 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/07 11:11:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

void	ft_set_pixel_Mandelbrot(int x, int y, t_complex *c, t_data *data);
int		ft_get_Mandelbrot_color(t_complex *c, t_complex *z);

#endif
