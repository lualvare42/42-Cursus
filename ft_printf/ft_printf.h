/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:27:55 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/16 11:31:32 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_print_char(va_list ap);
void	ft_print_str(va_list ap, int *i);
void	ft_print_decimal_int(va_list ap, int *i);
void	ft_print_unsigned(va_list ap, int *i);
void	ft_print_hex_lower(va_list ap, int *i);
void	ft_print_hex_upper(va_list ap, int *i);
void	ft_print_memory(va_list ap, int *i);
int		ft_printf(const char *s, ...);
#endif