/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:44:46 by manjaro           #+#    #+#             */
/*   Updated: 2021/06/29 17:34:33 by manjaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

void	ft_exit_with_error_var(char *error_message, char *additional_info,
			char color);
void	ft_exit_with_error(char *error_message, char color);
void	ft_exit_with_error_func(char *error_message, void (*func)(void *data),
			void *data, char color);

#endif
