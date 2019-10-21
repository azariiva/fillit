#include "libfi.h"

// static void deltetrff(t_tetr *tetr, char **map, t_coord place, char letter)
// {
//     int x;
//     int y;

//     y = 0;
//     while (y <= tetr->dright.y - tetr->uleft.y)
//     {
//         x = 0;
//         while (x <= tetr->dright.x - tetr->uleft.x)
//         {
//             if (tetr->body[(y + tetr->uleft.y) * TETR_SIZE + x + tetr->uleft.x] == letter)
//                 map[place.y + y][place.x + x] = EMPTY;
//             ++x;
//         }
//         ++y;
//     }
// }



static void deltetrff(t_coord place, char letter, t_field *map)
{
    int x;
    int y;

    y = place.y;
    while (y < 4 + place.y && y < map->size)
    {
        x = place.x;
        while (x < 4 + place.x && x < map->size)
        {
            if (map->body[y][x] == letter)
                map->body[y][x] = EMPTY;
            ++x;
        }
        ++y;
    }
}

t_err puttetrlst(t_list *lst, t_field *map, char letter)
{
    t_coord place;
    int flag;

    place.y = 0;
    place.x = -1;
    while (place.y < map->size)
    {
        flag = 0;
        while (!flag && ++place.x < map->size)
        {
            if (puttetr(lst->content, map, place, letter) == OK)
                flag = 1;
        }
        while (!flag && ++place.y < map->size)
        {
            place.x = -1;
            while (!flag && ++place.x < map->size)
            {
                if (puttetr(lst->content, map, place, letter) == OK)
                    flag = 1;
            }
        }
        if (!flag)
        {
            // for (int i = 0; i < map->size; i++)
            // {
            //     for (int j = 0; j < map->size; j++)
            //         ft_putchar(map->body[i][j]);
            //     ft_putchar('\n');
            // }
            // ft_putchar('\n');
            return (ERR);
        }
        else if (!lst->next || puttetrlst(lst->next, map, letter + 1) == OK)
            return (OK);
        // for (int i = 0; i < map->size; i++)
        //     {
        //         for (int j = 0; j < map->size; j++)
        //             ft_putchar(map->body[i][j]);
        //         ft_putchar('\n');
        //     }
        //     ft_putchar('\n');
        //deltetrff((t_tetr *)lst->content, map->body, place, letter);
        deltetrff(place, letter, map);
        // for (int i = 0; i < map->size; i++)
        //     {
        //         for (int j = 0; j < map->size; j++)
        //             ft_putchar(map->body[i][j]);
        //         ft_putchar('\n');
        //     }
        //     ft_putchar('\n');
        // ft_putchar('\n');
    }
    return (ERR);
}