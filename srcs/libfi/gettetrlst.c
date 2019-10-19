#include "libfi.h"

t_list  *gettetrlst(int fd)
{
    t_list  *lst;
    t_list  *ptr;
    char    *tetr;
    t_err   err;

    lst = NULL;
    if ((err = gettetr(fd, &tetr)) != ERR)
    {
        if (!(lst = ft_lstnew(tetr, TETR_SIZE * TETR_SIZE)))
            return (NULL);
        ptr = lst;
        while (err == OK)
        {
            err = gettetr(fd, &tetr);
            ptr->next = ft_lstnew(tetr, TETR_SIZE * TETR_SIZE);
            ptr = ptr->next;
        }
        if (err == ERR)
            ft_lstdel(&lst, &deltetr);
    }
    return (lst);
}