/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 02:34:30 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/22 21:45:45 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

/////////
void	ft_print_parse(t_all *aio);
//////////

int		ft_cub3d(char *cub)
{
	t_all	*aio;

	aio = ft_init_all_in_one();
	aio->mlx.ptr = mlx_init();
	if (ft_parse(aio, cub) == -1)
		return (ft_exit(aio, 0));
///
ft_print_parse(aio);
///
	//aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->win.x, aio->win.y, "cub3D");
//
ft_mlx_map(aio);
//
	//mlx_loop(aio->mlx.ptr);
	return (1);
}

int			main(int argc, char **argv)
{
//	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
//		ft_init(av[1], 1);
	//else
	if (argc == 2 && check_file_extension(argv[1], "cub"))
		ft_cub3d(argv[1]);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}










void	ft_print_parse(t_all *aio)
{
	int i = 0;

	ft_putnbr_fd(aio->map.x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(aio->map.y, 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd(aio->tex.no, 1);
	ft_putendl_fd(aio->tex.so, 1);
	ft_putendl_fd(aio->tex.we, 1);
	ft_putendl_fd(aio->tex.ea, 1);
	ft_putendl_fd(aio->tex.sprite, 1);
	while (i < 3)
	{
		ft_putnbr_fd(aio->tex.floor[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	i = 0;
	while (i < 3)
	{
		ft_putnbr_fd(aio->tex.ceil[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	i = 0;
	while (aio->map.walls[i])
	{
		ft_putendl_fd(aio->map.walls[i], 1);
		i++;
	}
	printf("PLAER x-%d y-%d view%d", aio->plr.x, aio->plr.y, aio->plr.view);
}
