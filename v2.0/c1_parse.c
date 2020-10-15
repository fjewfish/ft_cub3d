/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:17 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/14 22:52:32 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

int		ft_rnswesfc(t_all *aio, char *line);
int		ft_skip_spases(char *line, int *i);
int		ft_atoi_i(char *line, int *i);
int		ft_resolution(t_all *aio, char *line, int *i);
int		ft_texture(t_all *aio, unsigned int **adr, char *line, int *i, char **texture);
int		ft_rgb(unsigned int *color, char *line, int *i);
int		ft_makemap_list(t_all *aio, char *line);

int		ft_skip_spases(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi_i(char *line, int *i)
{
	int	num;

	num = 0;
	ft_skip_spases(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}
/* ************************************************************************** */
int		ft_parse(t_all *aio, char *cub)
{
	char	*line;
	int		fd;
	int		err;
	int		i;

	err = 1;
	i = 0;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_error_number(-1)); //Error : Couldn't open file (FD)
	while (err == 1)
	{
		err = get_next_line(fd, &line);
		if (err == 1 && aio->parse_error.map_trigger == 0)
			err = ft_rnswesfc(aio, line);//Error : Couldn't parse file (GNL)
		if (err == 1 && aio->parse_error.map_trigger == 1)
		{
			ft_skip_spases(line, &i);
			if (aio->parse_error.map_empty_line == 0 && line[i] == '\0')
				ft_makemap_list(aio, line);
		}
		free(line);
	}
	close(fd);
	err = ft_map_parse(aio);
	if (err < 0)
		return (ft_error_number(err));//?????
	ft_pos(aio);
	//aio->spr = NULL;
	//ft_slist(s);
	return (ft_parcheck(aio));
}

int		ft_rnswesfc(t_all *aio, char *line)
{
	int		i;

	i = 0;
	ft_skip_spases(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_resolution(aio, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.no, line, &i, &aio->tex.north);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.so, line, &i, &aio->tex.south);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.we, line, &i, &aio->tex.west);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.ea, line, &i, &aio->tex.east);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.sp, line, &i, &aio->tex.sprite);

	else if (line[i] == 'F' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.fl, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.ce, line, &i);
	else
		aio->parse_error.map_trigger == 1;
	ft_skip_spases(line, &i);
	if (aio->parse_error.settings == 0 && line[i] != '\0')
		return (-10);
	return (aio->parse_error.settings);
}

int		ft_resolution(t_all *aio, char *line, int *i)
{
	if (aio->res.map_x != 0 || aio->res.map_y != 0)
		return (-3);
	(*i)++;
	aio->res.map_x = ft_atoi_i(line, i);
	aio->res.map_y = ft_atoi_i(line, i);
	if (aio->res.map_x > aio->res.display_x)
		aio->res.map_x = aio->res.display_x;
	if (aio->res.map_y > aio->res.display_y)
		aio->res.map_y = aio->res.display_y;
	ft_skip_spases(line, i);
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int		ft_texture(t_all *aio, unsigned int **adr, char *line, int *i, char **texture)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_skip_spases(line, i);
	*texture = ft_strdup_gc(&line[*i]);
	(*i) += ft_strlen(*texture);
	if (ft_namecheck(texture, "xpm") == 0)
		return (-1);
	if ((fd = open(texture, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(aio->mlx.ptr, texture, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		ft_rgb(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi_i(line, i);
	if (line[*i] != ',')
		return (-6);
	(*i)++;
	g = ft_atoi_i(line, i);
	if (line[*i] != ',')
		return (-6);
	(*i)++;
	b = ft_atoi_i(line, i);
	ft_skip_spases(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

int		ft_makemap_list(t_all *aio, char *line)
{
	if (!aio->map.list)
		aio->map.list = ft_lstnew(line);
	else
		ft_lstadd_back(&aio->map.list, ft_lstnew(line));
	return(0);
}

int		ft_map_parse(t_all *aio)
{
	aio->map.height = ft_lstsize(aio->map.list);
	if (!(*aio->map.map = (char *)malloc(aio->map.height)))
		return(-11);

}

int		ft_slablen(t_all *s, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (s->map.width != 0 && s->map.width != count)
		return (-1);
	return (count);
}

char	*ft_slab(t_all *s, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (ft_slablen(s, line) + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			slab[j++] = line[*i];
		else if (line[*i] == '2')
		{
			slab[j++] = line[*i];
			s->map.sprite_count++;
		}
		else if (line[*i] != ' ')
		{
			free(slab);
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int		ft_map(t_all *aio, char *line, int *i)
{
	char	**tmp;
	int		j;

	aio->map.err_map = 1;
	if (!(tmp = malloc(sizeof(char *) * (aio->map.height + 2))))
		return (-11);
	j = -1;
	while (++j < aio->map.height)
		tmp[j] = aio->map.map[j];
	if ((tmp[aio->map.height] = ft_slab(aio, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[aio->map.height + 1] = NULL;
	if (aio->map.height > 0)
		free(aio->map.map);
	aio->map.map = tmp;
	aio->map.height++;
	if ((aio->map.width = ft_slablen(aio, line)) == -1)
		return (-13);
	return (0);
}

