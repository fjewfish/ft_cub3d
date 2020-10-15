/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_flags 2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:06:32 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		if_dot(const char *line, int *aiotart,
			t_fps *format_str, va_list argptr)
{
	(*aiotart)++;
	if (line[*aiotart] == '*')
	{
		format_str->dot = va_arg(argptr, int);
		(*aiotart)++;
		format_str->length_format++;
	}
	else
	{
		format_str->dot = 0;
		while (ft_isdigit(line[*aiotart]))
		{
			format_str->dot = (format_str->dot * 10) + (line[*aiotart] - '0');
			(*aiotart)++;
			format_str->length_format++;
		}
	}
	if (format_str->dot < 0)
		format_str->dot = -1;
	format_str->length_format++;
}

void		if_minus(t_fps *format_str)
{
	format_str->minus = 1;
	format_str->null = 0;
	format_str->length_format++;
}

void		if_width(va_list argptr, t_fps *format_str)
{
	format_str->width = va_arg(argptr, int);
	if (format_str->width < 0)
	{
		format_str->minus = 1;
		format_str->width *= -1;
		if (format_str->null == 1)
			format_str->null = 0;
	}
	format_str->length_format++;
	format_str->star_double = 1;
}

void		if_digit(char digit, t_fps *format_str)
{
	if (format_str->star_double == 1)
		format_str->width = 0;
	format_str->width = (format_str->width * 10) + (digit - '0');
	format_str->length_format++;
}
