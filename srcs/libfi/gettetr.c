#include "libfi.h"

t_err   gettetr(int fd, char *tetr)
{
    int     i;

    i = 0;
    while (i < TETR_SIZE)
    {
        if (read(fd, tetr + i * TETR_SIZE, TETR_SIZE) != TETR_SIZE)
            return (ERR);
        if (ft_getc(fd) != '\n')
            return (ERR);
        ++i;
    }
    if ((i = ft_getc(fd)) != '\n' && i)
        return (ERR);
    return (i ? OK : END);
}