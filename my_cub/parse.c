/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:48:18 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/21 13:15:51 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	ft_write_texture(t_all *aio, t_list **tmp)
{
	int		i;
	char *str;
	i = 0;
	str = (char *)(*tmp)->content);
	while (*tmp && (ft_check_map_start(str == 1));
	{
		while(str[i++])
		{
			if ()??????????/
		}
		(*tmp) = (*tmp)->next;
	}
}

void	make_map(t_list **head, int size, t_all *aio)
{
	int i;
	t_list *tmp;

	aio->map.walls = calloc_gc((size + 1), sizeof(char *));
	i = -1;
	tmp = *head;
	if (ft_check_map(tmp) == 1)
	{
		ft_write_texture(aio, &tmp);
		while (tmp)
		{
			aio->map.walls[++i] = tmp->content;
			tmp = tmp->next;
		}
	}
	else
		ft_strerror(999);
}

static void		pointer_free(void *ptr)
{
	free(ptr);
}

int		ft_parse(t_all *aio, char *cub)
{
	int fd;
	char *line;
	t_list *head;

	line = NULL;
	head = NULL;
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
	ft_lstclear(&head, &pointer_free);
	return(1);
}
