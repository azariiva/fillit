/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:57:37 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/21 12:43:30 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*head;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	next = lst->next;
	head = f(lst);
	lst = next;
	ptr = head;
	while (lst && ptr)
	{
		next = lst->next;
		ptr->next = f(lst);
		ptr = ptr->next;
		lst = next;
	}
	return (head);
}
