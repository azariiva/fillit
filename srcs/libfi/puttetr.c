#include "libfi.h"

static void placetetr(t_tetr *tetr, char **map, t_coord place, char letter)
{
    int x;
    int y;

    y = 0;
    while (y <= tetr->dright.y - tetr->uleft.y)
    {
        x = 0;
        while (x <= tetr->dright.x - tetr->uleft.x)
        {
            if (tetr->body[(y + tetr->uleft.y) * TETR_SIZE + x + tetr->uleft.x] == FILLED) 
                map[place.y + y][place.x + x] = letter;
            ++x;
        }
        ++y;
    }
}

t_err       puttetr(t_tetr *tetr, t_field *map, t_coord place, char letter)
{
    int y;
    int x;
    
    if (tetr->dright.x - tetr->uleft.x + place.x >= map->size || tetr->dright.y - tetr->uleft.y + place.y >= map->size)
        return (ERR);
    y = 0;
    while (y <= tetr->dright.y - tetr->uleft.y)
    {
        x = 0;
        while (x <= tetr->dright.x - tetr->uleft.x)
        {
            if (ft_isupper(map->body[place.y + y][place.x + x]) && tetr->body[(y + tetr->uleft.y) * TETR_SIZE + x + tetr->uleft.x] == FILLED)
                return (ERR);
            ++x;
        }
        ++y;
    }
    placetetr(tetr, map->body, place, letter);
    return (OK);
}