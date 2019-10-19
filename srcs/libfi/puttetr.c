#include "libfi.h"

void    puttetr(char *tetr)
{
    size_t  i;

    if (tetr)
    {
        i = 0;
        while (i < TETR_SIZE)
        {
            write(1, tetr + i++ * TETR_SIZE, TETR_SIZE);
            ft_putchar('\n');
        }
        ft_putchar('\n');
    }
    else
        ft_putendl("NULL\n");
}