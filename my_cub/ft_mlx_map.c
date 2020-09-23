#include "main_header.h"

int		ft_keyboard(int key, t_all *aio);


void            my_mlx_pixel_put(t_img *data, int x, int y, int color, int plr_wall, int view)
{
    char    *dst;
	int save_x;
	int save_y;

	x = x*SCALE;
	y = y*SCALE;
	save_y = y;
	save_x = x;
	if (plr_wall == 1)
	{
		while (x < save_x+SCALE)
		{
			y = save_y;
			while (y< save_y+SCALE)
			{
				dst = (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
				*(unsigned int*)dst = color;
				y++;
			}
			x++;
		}
	}
	else if (plr_wall == 2)
	{
		if (view == 90)
		{
			int left = SCALE/2;
			int rigt = SCALE/2;
			while (y < save_y+SCALE/2)
			{
				x = save_x;
				while (x < save_x+SCALE-left)
						x++;
				left++;
				while (x< save_x+SCALE-rigt)
				{
					dst = (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
					*(unsigned int*)dst = color;
					x++;
				}
				rigt--;
				y++;
			}
		}
		if (view == 180)
		{
			int left = SCALE/2;
			int rigt = SCALE/2;
			while (x < save_x+SCALE/2)
			{
				y = save_y;
				while (y < save_y+SCALE-left)
						y++;
				left++;
				while (y< save_y+SCALE-rigt)
				{
					dst = (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
					*(unsigned int*)dst = color;
					y++;
				}
				rigt--;
				x++;
			}
		}
		////////////////////////////////////////////////////////
		if (view == 0)
		{
			int left = SCALE/2;
			int rigt = SCALE/2;
			x+=SCALE;
			while (x > save_x+SCALE/2)
			{
				y = save_y;
				while (y < save_y+SCALE-left)
						y++;
				left++;
				while (y< save_y+SCALE-rigt)
				{
					dst = (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
					*(unsigned int*)dst = color;
					y++;
				}
				rigt--;
				x--;
			}
		}
		if (view == 270)
		{
			int left = SCALE/2;
			int rigt = SCALE/2;
			y+=SCALE;
			while (y > save_y+SCALE/2)
			{
				x = save_x;
				while (x < save_x+SCALE-left)
						x++;
				left++;
				while (x< save_x+SCALE-rigt)
				{
					dst = (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
					*(unsigned int*)dst = color;
					x++;
				}
				rigt--;
				y--;
			}
		}
	}
}

void	ft_draw(t_all *aio)
{
	int i = 0;
	int j = 0;

	free(aio->img.ptr);
	free(aio->img.addr);
	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->map.x, aio->map.y);
    aio->img.addr = mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length,
                                 &aio->img.endian);
	while (aio->map.walls[i])
	{
		j = 0;
		while (aio->map.walls[i][j])
		{
			if (aio->map.walls[i][j] == '1')
				my_mlx_pixel_put(&aio->img, j, i, RED, 1, aio->plr.view);
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(&aio->img, aio->plr.x, aio->plr.y, GREEN, 2, aio->plr.view);
	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
}

void	ft_mlx_map(t_all *aio)
{
	//aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->win.x, aio->win.y, "cub2D");

	//mlx_loop(aio->mlx.ptr);

    //t_data  img;
	//int i_scale = 0;
	//int j_scale = 0;

    aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->map.x, aio->map.y, "Hello world!");
	ft_draw(aio);
	mlx_hook(aio->win.ptr, 2, 1L<<0, ft_keyboard, aio);

    mlx_loop(aio->mlx.ptr);
}

int		ft_keyboard(int key, t_all *aio)
{
	if (key == ESC)
	{
		mlx_destroy_window(aio->mlx.ptr, aio->win.ptr);
		free(aio->mlx.ptr);
		exit(0);
	}
	else if (key == W)
		{
			if(aio->map.walls[aio->plr.y - 1][aio->plr.x] != '1')
				aio->plr.y -= 1;
		}
	else if (key == A)
		{
			if(aio->map.walls[aio->plr.y][aio->plr.x - 1] != '1')
				aio->plr.x -= 1;
		}
	else if (key == S)
		{
			if(aio->map.walls[aio->plr.y + 1][aio->plr.x] != '1')
				aio->plr.y += 1;
		}
	else if (key == D)
		{
			if(aio->map.walls[aio->plr.y][aio->plr.x + 1] != '1')
				aio->plr.x += 1;
		}
	else if (key == LEFT)
		{

		}
	else if (key == RIGHT)
		{
			if(aio->map.walls[aio->plr.y][aio->plr.x + 1] != '1')
				aio->plr.x += 1;
		}
		ft_draw(aio);
	return (1);
}

