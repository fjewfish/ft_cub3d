/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:48:18 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/21 10:26:35 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
??????????????????????????????
void	**make_map(t_list **head, int size, t_all *aio)
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

int		ft_parse(t_all *aio, char *cub)
{
	int fd;
	char *line;
	t_list *head;

	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(999));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), aio);

	//PRINT GNL
	int i = 0;
	while (aio->map.walls[i])
	{
		ft_putendl_fd(aio->map.walls[i], 1);
		i++;
	}
	//DEL ALL UP
	return(1);
}
