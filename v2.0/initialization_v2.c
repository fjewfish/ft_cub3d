#include "main_header_v2.h"

void		ft_initialization(t_all *aio)
{
	aio->mlx.ptr = NULL;
	aio->win.ptr = NULL;
	aio->img.adr = NULL;
	aio->img.ptr = NULL;
	aio->map.height = 0;
	aio->map.map = NULL;
	aio->map.width = 0;
	aio->map.height = 0;
	aio->map.width = 0;
	aio->tex.east = NULL;
	aio->tex.north = NULL;
	aio->tex.south = NULL;
	aio->tex.sprite = NULL;
	aio->tex.west = NULL;
	aio->res.map_x = 0;
	aio->res.map_y = 0;
	aio->map.err_map = 0;
	aio->map.err_map = 0;
	aio->res.display_x = 0;
	aio->res.display_y = 0;
	aio->plr.dir_x = 0;
	aio->plr.dir_y = 0;
	aio->plr.pos_x = 0;
	aio->plr.pos_y = 0;
	aio->tex.ce = NONE;
	aio->tex.fl = NONE;
	aio->tex.ea = 0;
	aio->tex.no = 0;
	aio->tex.so = 0;
	aio->tex.sp = 0;
	aio->tex.we = 0;
	aio->map.err_player = 0;
	aio->map.err_map = 0;
	aio->map.err_parse = 0;
	aio->map.list = NULL;
	aio->key.a = 0;
	aio->key.d = 0;
	aio->key.e = 0;
	aio->key.h = 0;
	aio->key.l = 0;
	aio->key.r = 0;
	aio->key.s = 0;
	aio->key.w = 0;
	aio->key.x = 0;
	aio->map_mode = 0;



	////////////
	aio->parse_error.map_trigger == 0;
}
