/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi 2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:38:18 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *aiotr)
{
	unsigned long long int	result;
	int						symbol;
	size_t					i;

	result = 0;
	symbol = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == 45)
		symbol = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	return ((int)(symbol * result));
}
