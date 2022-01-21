/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:40 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include "string.h"
# include "stdlib.h"
# include "unistd.h"

void		ft_bzero(void *a, size_t bytes); //full complete
void		*ft_memset(void *a, int b, size_t c); //full complete
void		*ft_memcpy( void *dest, const void *src, size_t count ); //fc
void		*ft_memmove(void *dest, const void *src, size_t count); //fc
void		*ft_memchr(const void *arr, int c, size_t n); //fc if not n-t
int			ft_memcmp( const void *lhs, const void *rhs, size_t count ); //fc
int			ft_isprint(int ch); //full complete ?
int			ft_isalnum(int c);
int			ft_isdigit(int ch); //full complete ?
int			ft_isascii(int ch); //full complete ?
int			ft_isalpha(int ch); //full complete ?
int			ft_atoi(const char *src); //full complete
int			main(void);
const char	*ft_strchr(const char *str, int c); //full complete
const char	*ft_strrchr(const char *str, int c); //full complete
char		*ft_strnstr(const char *first, const char *second, size_t len); //fc
int			ft_strncmp(const char *s1, const char *s2, size_t n);//full complete
size_t		ft_strlcpy(char *dst, const char *src, size_t size); //full complete
size_t		ft_strlcat(char *dst, const char *src, size_t size); //i guess...
size_t		ft_strlen(const char *string); //full complete
int			ft_toupper(int ch); //full complete
int			ft_tolower(int ch); //full complete
void		*ft_calloc(size_t number, size_t size); //fc
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
#endif
