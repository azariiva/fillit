#include "libfi.h"
#include <fcntl.h>

static void cleanbody(char **map, int realsize)
{
    int i;

    i = 0;
    while (i < realsize)
    {
        free(map[i++]);
    }
    free(map);
}

static int makemap(t_field *map, int lstsize)
{
    map->realsize = (lstsize == 1 ? 4 : lstsize * 3);
    if (!(map->body = (char **)malloc(map->realsize * sizeof(char *))))
        return (ERR);
    for (int i = 0; i < map->realsize; i++)
    {
        if (!(map->body[i] = (char *)malloc(map->realsize * sizeof(char))))
        {
            cleanbody(map->body, i);
            return (ERR);
        }

        for (int j = 0; j < map->realsize; j++)
            map->body[i][j] = '.';
    }
    map->size = 2;
    return (OK);
}

int main(int ac, char **av)
{
    int fd;
    t_list *tetrlst;
    t_field map;

    if (ac != 2)
    {
        //TODO: Show usage of program
        return (0);
    }
    if ((fd = open(av[1], O_RDONLY)) < 0 || !(tetrlst = gettetrlst(fd)))
    {
        ft_putendl("error");
        return (0);
    }
    if (validatelst(tetrlst) == ERR || makemap(&map, ft_lstsize(tetrlst)) == ERR)
    {
        ft_lstdel(&tetrlst, &deltetr);
        ft_putendl("error");
        return (0);
    }
    while (puttetrlst(tetrlst, &map, 'A') == ERR)
    {
        map.size++;
        for (int i = 0; i < map.size; i++)
        {
            for (int j = 0; j < map.size; j++)
                map.body[i][j] = EMPTY;
        }
    }
    for (int i = 0; i < map.size; i++)
    {
        for (int j = 0; j < map.size; j++)
            ft_putchar(map.body[i][j]);
        ft_putchar('\n');
    }
    ft_lstdel(&tetrlst, &deltetr);
    return (0);
}