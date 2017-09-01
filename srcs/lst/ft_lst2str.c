#include "libft.h"

char	*ft_lst2str(t_list *list)
{
	size_t		size;
	t_list		*tmp;
	char		*new;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size += ft_strlen((char *)tmp->content) + 1;
		tmp = tmp->next;
	}
	new = ft_memalloc(size);
	while (list)
	{
		ft_strcat(new, (char *)list->content);
		if (list->next)
			ft_strcat(new, "  ");
		list = list->next;
	}
	return (new);
}
