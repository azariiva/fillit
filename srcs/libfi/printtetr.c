#include "libfi.h"

void    printtetr(t_tetr *tetr)
{
    size_t  i;

    if (tetr)
    {
        i = 0;
        while (i < TETR_SIZE)
        {
            write(1, tetr->body + i++ * TETR_SIZE, TETR_SIZE);
            ft_putchar('\n');
        }
        ft_putchar('\n');
        ft_putstr("UL: ");
        ft_putnbr(tetr->uleft.x);
        ft_putstr(" : ");
        ft_putnbr(tetr->uleft.y);
        ft_putchar('\n');
        ft_putstr("DR: ");
        ft_putnbr(tetr->dright.x);
        ft_putstr(" : ");
        ft_putnbr(tetr->dright.y);
        ft_putendl("\n");
    }
    else
        ft_putendl("NULL\n");
}