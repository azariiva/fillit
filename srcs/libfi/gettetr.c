#include "libfi.h"

t_err   gettetr(int fd, char **tetr)
{
    char    *tmp;
    int     i;

    *tetr = NULL;
    if (!(tmp = (char *) malloc(TETR_SIZE * TETR_SIZE * sizeof(char))))
        return (ERR);
    i = 0;
    while (i < TETR_SIZE)
    {
        if (read(fd, tmp + i * TETR_SIZE, TETR_SIZE) != TETR_SIZE)
        {
            free(tmp);
            return (ERR);
        }
        if (ft_getc(fd) != '\n')
        {
            free(tmp);
            return (ERR);
        }
        ++i;
    }
    if ((i = ft_getc(fd)) != '\n' && i)
    {

        free(tmp);
        return (ERR);
    }
    *tetr = tmp;
    return (i ? OK : END);
}