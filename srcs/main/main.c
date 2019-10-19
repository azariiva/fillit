#include "libfi.h"
#include <fcntl.h>

int main(int ac, char **av)
{
    int     fd;
    t_list  *tetrlst;

    if (ac != 2) {
        //TODO: Show usage of program
        return (0);
    }
    if ((fd = open(av[1], O_RDONLY)) < 0 || !(tetrlst = gettetrlst(fd)) || validatelst(tetrlst) == ERR) {
        ft_putendl("error");
        return (0);
    }
    puttetrlst(tetrlst);
    ft_lstdel(&tetrlst, &deltetr);
    return (0);
}