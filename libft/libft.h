/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:39:21 by jjaouen           #+#    #+#             */
/*   Updated: 2017/06/02 06:15:13 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FILLED filed
# define CONT ((t_filed *)(tmp->content))
# include "ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[91m"
# define KGRN  "\x1B[92m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[1m"


void				ft_free_gnl(int fd);
char				*ft_strtrim_all(char *str);
void				ft_free_words_tables(char ***tab);
int					ft_tablen(char **tab);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_uimt(uintmax_t n);
void				ft_move_char_right(char *dst, char c, int n);
intmax_t			ft_atoi_imt(const char *nptr);
void				ft_print_words_tables_fd(int fd, char **tab);
char				*ft_itoa_imt(intmax_t n);
char				*ft_itoa_base_imt(intmax_t value, int base);
char				*ft_itoa_base_uimt(uintmax_t value, int base);
char				*ft_strsubf(char const *s, unsigned int start, size_t len);
char				*ft_itoa_base(int value, int base);
int					ft_atoi_base(const char *str, int base);
char				*ft_strjoinf(char const *s1, char const *s2, int f);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dst, char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(char const *s);
char				*ft_strdup(char const *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memallocexit(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *nptr);
long				ft_atoi_long(const char *nptr);
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
int					ft_is_sort(int *tab, int length, int (*f)(int, int));
int					ft_count_if(char **tab, int (*f)(char*));
char				*ft_strmaj(char *str);
int					ft_strchrint(const char *s, int c);
char				*ft_replace_char(char *src, char modif, char replace);

typedef struct		s_filed
{
	char			*buff;
	int				fd;
	int				h;
	ssize_t			sizebuff;
}					t_filed;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_count_list(t_list *list);
int					ft_sqrt(int nb);
void				ft_print_words_tables(char **tab);
void				ft_lstadd_end(t_list **alst, t_list *new);

#endif
