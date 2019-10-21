#include "libfi.h"

t_err   validatelst(t_list *lst)
{
    while (lst) {
        if (validate(((t_tetr *)lst->content)->body) == ERR)
            return (ERR);
        lst = lst->next;
    }
    return (OK);
}