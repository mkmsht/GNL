#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define SAFE_FREE(ptr) { free(ptr); ptr = NULL; }

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *p, int ch);

#endif
