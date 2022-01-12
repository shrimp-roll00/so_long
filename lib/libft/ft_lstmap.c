#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*util;
	t_list	*res;

	if (!lst)
		return (0);
	res = 0;
	while (lst)
	{
		util = ft_lstnew(f(lst->content));
		if (!util)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, util);
		lst = lst->next;
	}
	return (res);
}
