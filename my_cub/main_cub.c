/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 02:34:30 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/21 05:56:59 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int		ft_cub3d(char *cub)
{
	t_all	*aio;

	aio = ft_init_all_in_one();
	aio->mlx.ptr = mlx_init();
	if (ft_parse(aio, cub) == -1)
		return (ft_exit(aio, 0));
	mlx_loop(aio->mlx.ptr);
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
