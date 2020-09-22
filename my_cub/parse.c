/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:48:18 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/23 01:56:31 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	ft_print_parse(t_all *aio);
void	ft_find_plr(char **walls, t_all *aio);

int		ft_atoi_i(char *str, size_t *i)
{
	unsigned long long int	result;
	int						symbol;

	result = 0;
	symbol = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		++(*i);
	if (str[*i] == 45)
		symbol = -1;
	if (str[*i] == '+' || str[*i] == '-')
		++(*i);
	if (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		return (0);
	while (str[*i] >= 48 && str[*i] <= 57)
	{
		result = result * 10 + str[*i] - 48;
		++(*i);
	}
	return ((int)(symbol * result));
}

void	ft_wr_FC(char *str, int fc[3])
{
	size_t	i;

	i = 0;
	fc[0] = ft_atoi_i(str, &i);
	i++;
	fc[1] = ft_atoi_i(str, &i);
	i++;
	fc[2] = ft_atoi_i(str, &i);
}

void	ft_wr_resolution(char *str, int *x, int *y)
{
	size_t	i;

	i = 0;
	*x = ft_atoi_i(str, &i);
	*y = ft_atoi_i(str, &i);
}

void	ft_wr_texture(char *str, char **tex)
{
	*tex = ft_strdup_gc(str);
}

void	make_map(t_list **head, t_all *aio)
{
	int i;
	t_list *tmp;
	char *str;

	tmp = *head;
	i = -1;
	while (tmp)
	{
		str = (char *)tmp->content;
		if (str[0] == 'R')
		{
			ft_wr_resolution(&str[2], &(aio->map.x), &(aio->map.y));
			aio->win.x = aio->map.x;
			aio->win.y = aio->map.y;
		}
		else if (str[0] == 'N' && str[1] == 'O')
			ft_wr_texture(&str[3], &aio->tex.no);
		else if (str[0] == 'S' && str[1] == 'O')
			ft_wr_texture(&str[3], &aio->tex.so);
		else if (str[0] == 'W' && str[1] == 'E')
			ft_wr_texture(&str[3], &aio->tex.we);
		else if (str[0] == 'E' && str[1] == 'A')
			ft_wr_texture(&str[3], &aio->tex.ea);
		else if (str[0] == 'S' && str[1] == ' ')
			ft_wr_texture(&str[2], &aio->tex.sprite);
		else if (str[0] == 'F')
			ft_wr_FC(&str[2], aio->tex.floor);
		else if (str[0] == 'C')
			ft_wr_FC(&str[2], aio->tex.ceil);
		else
		{
			aio->map.walls = calloc_gc((ft_lstsize(tmp) + 1), sizeof(char *));
			while (tmp)
			{
				aio->map.walls[++i] = ft_strdup_gc((char *)tmp->content);
				tmp = tmp->next;
				//ft_putendl_fd(aio->map.walls[i], 1);
			}
			//aio->map.walls[++i] = (char *)tmp->content;
		}
		if (tmp != NULL)
			tmp = tmp->next;
	}
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
	int size_tex;

	line = NULL;
	head = NULL;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(999));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	if (ft_check_map(head) == 1)
		make_map(&head, aio);
	else
		ft_strerror(999);
	ft_find_plr(aio->map.walls, aio);
	ft_lstclear(&head, &pointer_free);
	return(1);
}

void	ft_find_plr(char **walls, t_all *aio)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(walls[i])
	{
		j = 0;
		while(walls[i][j])
		{
			if (walls[i][j] == 'N')//N,S,E or W)
			{
				aio->plr.y = i;
				aio->plr.x = j;
				aio->plr.view = 90;
			}
			if (walls[i][j] == 'S')//N,S,E or W)
			{
				aio->plr.y = i;
				aio->plr.x = j;
				aio->plr.view = 270;
			}
			if (walls[i][j] == 'W')//N,S,E or W)
			{
				aio->plr.y = i;
				aio->plr.x = j;
				aio->plr.view = 180;
			}
			if (walls[i][j] == 'E')//N,S,E or W)
			{
				aio->plr.y = i;
				aio->plr.x = j;
				aio->plr.view = 0;
			}
			j++;
		}
		i++;
	}
}
