/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:48:18 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/18 19:03:32 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"

char	**make_map(t_list **head, int size)
{
	char **map;
	int i;
	t_list *tmp;

	map = ft_calloc((size + 1), sizeof(char *));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	t_list *head;
	char **map;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	map = make_map(&head, ft_lstsize(head));

	//PRINT GNL
	int i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}

	//MLX
	void	*mlx = NULL;
	void	*win = NULL;
	int		x = 100;
	int		y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "test");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	}
	mlx_loop(mlx);
	return (0);
}
