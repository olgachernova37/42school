/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:39:47 by emarko            #+#    #+#             */
/*   Updated: 2024/06/06 18:39:48 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct t_flag
{
	int	conv;
	int	left;
	int	zero;
	int	precision;
	int	prec_width;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	asterisk;
}	t_flag;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
t_flag	ft_flag_init(void);
void	ft_flagleft(t_flag *flags);
void	ft_flagplus(t_flag *flags);
int		ft_print_rflags(size_t width, size_t strlen, int flag_zero);
int		ft_print_lflags(size_t width, size_t strlen);
int		ft_printsign(int n, t_flag flags);
int		ft_printhash(int hash, int upper);
int		ft_isflag(int c);
int		ft_istype(int c);
int		ft_printc(int c);
int		ft_printchar(int c, t_flag flags);
int		ft_prints(char *str, size_t len);
int		ft_printstr(char *str, t_flag flags);
int		ft_printdec(int n, t_flag flags);
int		ft_printn(char *num, t_flag flags, size_t len);
char	*ft_xtoa(unsigned long int n);
int		ft_printhex(unsigned int n, t_flag flags, int upper);
size_t	ft_xtoalen(unsigned long int n);
int		ft_printptr(unsigned long int n, t_flag flags);
char	*ft_utoa(unsigned int n);
int		ft_printuni(unsigned int n, t_flag flags);
char	*get_next_line(int fd);

#endif
