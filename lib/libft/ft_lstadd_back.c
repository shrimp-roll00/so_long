#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*util;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		util = ft_lstlast(*lst);
		util->next = new;
	}
}
