#include "libfi.h"

void    printtetrlst(t_list *lst)
{
	while (lst)
	{
		printtetr(lst->content);
		lst = lst->next;
	}
}