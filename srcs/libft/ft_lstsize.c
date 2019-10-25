#include "libft.h"

size_t			ft_lstsize(t_list *lst)
{
	size_t  ctr;

	if (lst) {
		ctr = 0;
		while (lst)
		{
			++ctr;
			lst = lst->next;
		}
		return (ctr);
	}
	return (0);
}