#include "libfi.h"

static void     placetetr(t_tetr *tetr, char **map, t_coord place)
{
	int x;
	int y;

	y = -1;
	while (++y <= tetr->dright.y - tetr->uleft.y)
	{
		x = -1;
		while (++x <= tetr->dright.x - tetr->uleft.x)
			if (tetr->body[(y + tetr->uleft.y) * TETR_SIZE + x + tetr->uleft.x] == FILLED) 
				map[place.y + y][place.x + x] = tetr->color;
	}
}

static t_err    puttetr(t_tetr *tetr, t_field *map, t_coord place)
{
	int x;
	int y;
	
	if (tetr->dright.x - tetr->uleft.x + place.x >= map->size || tetr->dright.y - tetr->uleft.y + place.y >= map->size)
		return (ERR);
	y = -1;
	while (++y <= tetr->dright.y - tetr->uleft.y)
	{
		x = -1;
		while (++x <= tetr->dright.x - tetr->uleft.x)
			if (ft_isupper(map->body[place.y + y][place.x + x]) && tetr->body[(y + tetr->uleft.y) * TETR_SIZE + x + tetr->uleft.x] == FILLED)
				return (ERR);
	}
	placetetr(tetr, map->body, place);
	return (OK);
}

static void     deltetrff(t_coord place, t_tetr *tetr, t_field *map)
{
	int x;
	int y;

	y = place.y;
	while (y <= tetr->dright.y - tetr->uleft.y + place.y && y < map->size)
	{
		x = place.x;
		while (x <= tetr->dright.x - tetr->uleft.x + place.x && x < map->size)
		{
			if (map->body[y][x] == tetr->color)
				map->body[y][x] = EMPTY;
			++x;
		}
		++y;
	}
}

t_err           puttetrlst(t_list *lst, t_field *map)
{
	t_coord place;
	int     flag;

	place.y = 0;
	place.x = -1;
	while (place.y < map->size)
	{
		flag = 0;
		while (!flag && ++place.x < map->size)
			if (puttetr(lst->content, map, place) == OK)
				flag = 1;
		while (!flag && ++place.y < map->size)
		{
			place.x = -1;
			while (!flag && ++place.x < map->size)
				if (puttetr(lst->content, map, place) == OK)
					flag = 1;
		}
		if (!flag)
			return (ERR);
		else if (!lst->next || puttetrlst(lst->next, map) == OK)
			return (OK);
		deltetrff(place, (t_tetr *)lst->content, map);
	}
	return (ERR);
}