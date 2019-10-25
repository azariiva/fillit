#include "libft.h"

char    ft_getc(int fd)
{
	char    c;

	if (read(fd, &c, sizeof(char)) != 1)
		return (0);
	return (c);
}