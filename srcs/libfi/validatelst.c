#include "libfi.h"

t_err   validatelst(t_list *lst)
{
    while (lst) {
        if (validate(lst->content) == ERR)
            return (ERR);
        lst = lst->next;
    }
    return (OK);
}