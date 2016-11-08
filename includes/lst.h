/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 11:25:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

typedef struct s_list	t_list;

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list	*ft_lstnew_range(int a, int b);
void	ft_lsteadd(t_list **alst, t_list *new);
void	ft_lstnadd(t_list **alst, t_list *new, int n);
void	ft_lst_sort(t_list **begin_list, int (*cmp)());
void	ft_lst_print(t_list *list, void (*printer)());
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lst_sorted_merge(
		t_list **begin_list1,
		t_list *begin_list2,
		int (*cmp)());
void	ft_lst_sorted_insert(
		t_list **begin_list,
		t_list *insert,
		int (*cmp)());
void	ft_lst_delif(
		t_list **alist,
		void *data_ref,
		int (*cmp)(),
		void (*del)(void *, size_t));
void	ft_lst_delsub(
		t_list **alst,
		t_list *sub, int (*cmp)(),
		void (*del)(void *, size_t));
void	ft_lst_cfree(void *ptr, size_t size);
t_list	*ft_lst_filter(
		t_list *lst,
		void const *data_ref,
		t_list *(*f)(t_list *elem, void const *));
t_list	*ft_lst_removeif(
		t_list **alst,
		void *data_ref,
		int (*cmp)());
t_list	*ft_lst_find(
		t_list *begin_list,
		void *data_ref,
		int (*cmp)());
t_list	*ft_lstpop(t_list **lst);
void	ft_lst_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_lst_reverse(t_list **begin_list);

int		ft_diff(void *a, void *b);
t_list	*ft_id(t_list *a);

#endif
