/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:47:49 by doriani           #+#    #+#             */
/*   Updated: 2023/11/02 19:50:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 480
# endif

typedef int				t_fd;
struct					s_slnode
{
	void			*content;
	struct s_slnode	*next;
};
typedef struct s_slnode	t_sl_list;
struct s_dlnode
{
	void			*data;
	struct s_dlnode	*next;
	struct s_dlnode	*prev;
};
typedef struct s_dlnode	t_cl_list;
struct s_stack
{
	int				top;
	unsigned int	capacity;
	int				*array;
};
typedef struct s_stack	t_stack;
typedef enum e_direction
{
	straight,
	reverse
}						t_direction;
typedef enum e_sort_order
{
	ascending,
	descending
}						t_sort_order;
/* BASIC LIB FUNCTIONS PROTOTYPES */
char		*ft_itoa_8(int n);
char		*ft_itoa_16(unsigned long long int n, int uppercase);
/* CHARS MANAGEMENT FUNCTIONS PROTOTYPES */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
size_t		ft_isprint(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
/* STRINGS MANAGEMENT FUNCTIONS PROTOTYPES */
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrev(char *str);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* MEMORY MANAGEMENT FUNCTIONS PROTOTYPES */
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_memdel(void **ap);
void		ft_bzero(void *s, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
/* WRITES MANAGEMENT FUNCTIONS PROTOTYPES */
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_putendl(char *s);
int			ft_printf(const char *str, ...);
/* UTILS FUNCTIONS PROTOTYPES */
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
char		*ft_itoa(int n);
char		*ft_itoa_base(unsigned long long int n, int base, int is_upper);
char		*ft_uitoa(unsigned int n);
char		*ft_uitoa_base(unsigned long long int n, int base, int is_upper);
void		ft_swapc(char *a, char *b);
void		ft_swapi(int *a, int *b);
char		**ft_split(char *s, char *charset);
char		**ft_quoted_split(char *s, char *charset, char *quotes);
int			ft_split_count(char **split);
void		ft_split_clean(char **split);
char		*get_next_line(int fd);
/* MATH FUNCTIONS PROTOTYPES */
int			ft_abs(int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
/* DATA STRUCTURES MANAGEMENT FUNCTIONS PROTOTYPES */
/* STACKS MANAGEMENT FUNCTION PROTOTYPES */
t_stack		*st_init(unsigned int capacity);
t_stack		*st_build(int *array, int capacity);
int			st_is_full(t_stack *stack);
int			st_is_empty(t_stack *stack);
void		st_free(t_stack *stack);
void		st_push(t_stack *stack, int item);
int			st_pop(t_stack *stack);
int			st_peek(t_stack *stack);
void		st_rotate(t_stack *stack);
void		st_reverse_rotate(t_stack *stack);
/* SINGLY LINKED LISTS MANAGEMENT FUNCTION PROTOTYPES */
t_sl_list	*sl_create_node(void *content);
void		sl_insert_end(t_sl_list **lst, t_sl_list *new_node);
void		sl_insert_begin(t_sl_list **lst, t_sl_list *new_node);
int			sl_size(t_sl_list *lst);
t_sl_list	*sl_last(t_sl_list *lst);
void		sl_delete_node(t_sl_list *lst, void (*del)(void *));
void		sl_destroy_list(t_sl_list **lst, void (*del)(void *));
void		sl_foreach(t_sl_list *lst, void (*f)(void *));
t_sl_list	*sl_map(t_sl_list *lst, \
						void *(*f)(void *), void (*del)(void *));
/* CIRCULAR LINKED LISTS MANAGEMENT FUNCTION PROTOTYPES */
// defined in cl_list.c
t_cl_list	*cl_init_list(void);
t_cl_list	*cl_create_node(void *data);
void		cl_destroy_list(t_cl_list **head);
t_cl_list	*cl_build_list(void **array, int size);
void		cl_display(t_cl_list *head, t_direction direction, \
						void (*display)(void *));
// defined in cl_insertions.c
void		cl_insert_begin(t_cl_list *head, void *data);
void		cl_insert_end(t_cl_list *head, void *data);
void		cl_insert_by_position(t_cl_list *head, void *data, \
							int position);
// defined in cl_additions.c
void		cl_add_node_begin(t_cl_list *head, t_cl_list *new_node);
void		cl_add_node_end(t_cl_list *head, t_cl_list *new_node);
void		cl_add_node_by_position(t_cl_list *head, t_cl_list *new_node, \
							int position);
// defined in cl_removals.c
t_cl_list	*cl_remove_node(t_cl_list *node);
t_cl_list	*cl_remove_node_by_position(t_cl_list *head, int pos);
t_cl_list	*cl_remove_node_by_data(t_cl_list *head, void *data, \
										int (cmp_data)(void *, void *));
// defined in cl_deletions.c
void		cl_delete_begin(t_cl_list *head);
void		cl_delete_end(t_cl_list *head);
void		cl_delete_node(t_cl_list *node);
void		cl_delete_node_by_position(t_cl_list *head, int position);
void		cl_delete_list(t_cl_list *head);
// defined in cl_searches.c
int			cl_get_node_position(t_cl_list *head, void *data, \
						int (*cmp_data)(void *, void *));
t_cl_list	*cl_get_node_by_position(t_cl_list *head, int pos);
t_cl_list	*cl_get_node_by_data(t_cl_list *head, void *data, \
									int (*cmp_data)(void *, void *));
// defined in cl_data_management1.c
void		*cl_get_node_data(t_cl_list *node);
void		*cl_get_node_data_by_position(t_cl_list *head, int position);
void		cl_set_node_data(t_cl_list *node, void *data);
void		cl_set_node_data_by_position(t_cl_list *head, \
						void *data, int position);
// defined in cl_data_management2.c
t_cl_list	*cl_get_max_node(t_cl_list *head, int (*cmp_data)(void *, void *));
int			cl_get_max_node_position(t_cl_list *head, \
						int (*cmp_data)(void *, void *));
t_cl_list	*cl_get_min_node(t_cl_list *head, int (*cmp_data)(void *, void *));
int			cl_get_min_node_position(t_cl_list *head, \
						int (*cmp_data)(void *, void *));
// defined in cl_utils1.c
int			cl_size(t_cl_list *head);
int			cl_is_empty(t_cl_list *head);
void		cl_rotate(t_cl_list *head, t_direction direction);
void		cl_reverse(t_cl_list *head);
void		cl_sort(t_cl_list *head, t_sort_order order, \
						int (*cmp_data)(void *, void *));
// defined in cl_utils2.c
void		cl_swap_list_nodes(t_cl_list *a, t_cl_list *b);
void		cl_swap_list_nodes_by_position(t_cl_list *head, int a, int b);
t_cl_list	*cl_get_node_by_position(t_cl_list *head, int position);
t_cl_list	*cl_get_node_by_data(t_cl_list *head, void *data, \
						int (*cmp_data)(void *, void *));
int			cl_is_sorted(t_cl_list *head, t_sort_order order, \
						int (*cmp_data)(void *, void *));
// defined in cl_utils3.c
t_cl_list	*cl_dup_node(t_cl_list *node, void *(*dup_data)(void *));
t_cl_list	*cl_dup_node_by_position(t_cl_list *head, int position, \
						void *(*dup_data)(void *));
t_cl_list	*cl_dup_list(t_cl_list *head, void *(*dup_data)(void *));
void		cl_foreach(t_cl_list *head, void (*f)(void *));
t_cl_list	*cl_map(t_cl_list *head, void (*f)(void *), \
						void *(*dup_data)(void *));
/* TREES MANAGEMENT FUNCTION PROTOTYPES */
/* GRAPHS MANAGEMENT FUNCTIONS PROTOTYPES */
#endif
