#include "libfi.h"

void    puttetrlst(t_list *lst)
{
    while (lst)
    {
        puttetr(lst->content);
        lst = lst->next;
    }
}