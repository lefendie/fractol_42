/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:04:40 by lefendie          #+#    #+#             */
/*   Updated: 2021/07/27 16:13:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IMAGE_H
# define BUILD_IMAGE_H

void	ft_build_image_Julia(t_data *data);
void	ft_build_image_Mandelbrot(t_data *data);
int		ft_create_new_image(t_data *data);
int		ft_print_image(t_data *data);
int		ft_get_color_from_rgb(char *char_rgb);

#endif
