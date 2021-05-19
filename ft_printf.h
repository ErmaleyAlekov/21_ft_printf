#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list{
	int				null;
	int				number_zeros;
	int				minus;
	int				width;
	int				precision;
	int				prec2;
	char			type;
	void			*content;
	char			chAr;
	int				length;
	int				negative;
	int				not_yet;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_write(char *str2, char *str, int lst);
void			assign(t_list *info);
void			parser(va_list *args, char **str);
void			cleans(t_list *info);
int				ft_isdigit(int c);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(char const *str);
char			*ft_revers(char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_toupper(char *str);
void			integers(t_list *point,
					va_list *args, char *ale);
void			chars(t_list *point, va_list *args);
void			buffer(t_list *info);

#endif
