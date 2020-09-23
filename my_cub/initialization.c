/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:30:51 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/23 11:47:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

//void	ft_del_aio(void)
//{
//}

t_all		*ft_init_all_in_one(void)
{
	t_all *aio;
	aio = malloc_gc(sizeof(t_all));
	aio->mlx.ptr = NULL;
	aio->win.ptr = NULL;
	aio->tex.no = NULL;
	aio->tex.so = NULL;
	aio->tex.we = NULL;
	aio->tex.ea = NULL;
	aio->tex.sprite = NULL;
	aio->img.ptr = NULL;
	aio->img.addr = NULL;
	aio->plr.ray_lenght = 0;
	aio->plr.ray_radians = 0;
	return (aio);
}
