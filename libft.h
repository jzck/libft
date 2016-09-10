#ifndef LIBFT_H
#define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define SEP(x) (x == ' ' || x == '\t' || x == '\n')
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define NEG(x) (((x) < 0) ? 1 : 0)
# define POS(x) (((x) > 0) ? 1 : 0)
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define DIST(a, b) (ABS((a) - (b)))

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void	ft_debug(void);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*strchr(const char *s, int c);
char	*strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void	ft_lst_print(t_list *list, void (*printer)());
int		ft_lstsize(t_list *lst);
void	ft_lsteadd(t_list **alst, t_list *new);
void	ft_lstnadd(t_list **alst, t_list *new, int n);
t_list	*ft_lstlast(t_list *lst);
void	ft_lst_sorted_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
void	ft_lst_sorted_insert(t_list **begin_list, t_list *insert, int (*cmp)());
t_list	*ft_lstnew_range(int a, int b);
void	ft_lst_delif(t_list **alist, void *data_ref, int (*cmp)(), void (*del)(void *, size_t));
void	ft_lst_delsub(t_list **alst, t_list *sub, int (*cmp)(), void (*del)(void *, size_t));
void	ft_lst_cfree(void *ptr, size_t size);
t_list	*ft_lst_filter(t_list *lst, void const *data_ref, t_list *(*f)(t_list *elem, void const *));

int		ft_diff(void *a, void *b);
t_list	*ft_id(t_list *a);
#endif
