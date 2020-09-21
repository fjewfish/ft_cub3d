/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 04:17:28 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/21 13:14:09 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int		check_file_extension(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int		ft_check_map(t_list *tmp);
{
	return (1);
}

int		ft_check_map_start(char *str)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (-1);
	}
	return (1);
}
