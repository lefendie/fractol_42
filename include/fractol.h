/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:53:54 by lefendie          #+#    #+#             */
/*   Updated: 2021/08/08 14:06:40 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <errno.h>
# include <math.h>

# include "fractol_struct.h"
# include "fractal.h"
# include "color.h"
# include "build_image.h"
# include "position.h"
# include "mouse_controller.h"
# include "keyboard_controller.h"
# include "initializer.h"
# include "error_handler.h"
# include "free_malloc.h"
# include "process.h"
# include "Mandelbrot.h"
# include "Julia.h"

# define SUCCESS 1
# define FAILURE 0
# define WIN_HEIGHT 600
# define WIN_WIDTH 600
# define WIN_HEIGHT_HALF 300
# define WIN_WIDTH_HALF 300
# define COLOR_MAX 100

#endif
