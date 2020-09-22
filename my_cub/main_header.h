/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:09:41 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/23 00:31:37 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

#include "libft/libft.h"
#include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

//MAlLOC_GC
# define M_ADD 1
# define M_REMOVE 0

# define SCALE 30

typedef char		t_bool;

//typedef struct		s_list
//{
//	void			*content;
//	struct s_list	*next;
//}					t_list;

//CUB_3D
typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	//unsigned int	*adr;
	//int				fsh;
	// void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_img;

//typedef struct	s_err
//{
//	int				n;
//	int				m;
//	int				p;
//}				t_err;

typedef struct	s_tex
{
	//unsigned int	*n;
	//unsigned int	*s;
	//unsigned int	*e;
	//unsigned int	*w;
	//unsigned int	*i;
	//unsigned int	c;
	//unsigned int	f;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *sprite;
	int floor[3];
	int	ceil[3];
}				t_tex;

typedef struct	s_map
{
	char			**walls;
	int				x;
	int				y;
	//int				spr;
}				t_map;

//typedef struct	s_pos
//{
//	double			x;
//	double			y;
//}				t_pos;

//typedef struct	s_dir
//{
//	double			x;
//	double			y;
//	double			a;
//}				t_dir;

//typedef struct	s_ray
//{
//	double			x;
//	double			y;
//	int				i;
//	double			v;
//	double			w;
//}				t_ray;

//typedef struct	s_hit
//{
//	double			x;
//	double			y;
//	double			d;
//}				t_hit;

//typedef struct	s_spr
//{
//	double			x;
//	double			y;
//	double			d;
//}				t_spr;

//typedef struct	s_stk
//{
//	double			x;
//	double			y;
//	double			d;
//}				t_stk;

typedef struct	s_plr
{
	int			x;
	int			y;
	int			view;
}				t_plr;

typedef struct	s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	//t_err			err;
	t_map			map;
	t_tex			tex;
	t_plr			plr;
	//t_pos			pos;
	//t_dir			dir;
	//t_ray			ray;
	//t_hit			hit;
	//t_spr			*spr;
	//t_stk			*stk;
	void			(*del)(struct	s_all *self);
}				t_all;

//MAIN
int		ft_cub3d(char *cub);

//MALLOC_GC
void		*malloc_gc(size_t sizemem);
void		*calloc_gc(size_t nmemb, size_t size);
void		free_gc(void *ptr);
static int	pointer_compare(void *ptr1, void *ptr2);
static void	pointer_free(void *ptr);
void		memory_manager(void *ptr, t_bool action);
char	*ft_strdup_gc(const char *s1);

//CHECKER_C
int		check_file_extension(char *arg, char *ext);
int		ft_check_map(t_list *tmp);

//INITIALIZATION_C
t_all		*ft_init_all_in_one(void);

//EXIT_ERRORS_C
int		ft_exit(t_all *s, int win);

//PARSE_C
void	make_map(t_list **head, t_all *aio);
int		ft_parse(t_all *aio, char *cub);

//USEFULL_FUN_C
int		ft_spaceskip(char *line, int *i);
int		ft_strerror(int err);






//DEL
void	ft_mlx_map(t_all *aio);

#endif
