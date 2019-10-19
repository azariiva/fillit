#ifndef LIBFI_H

# define LIBFI_H

# include "libft.h"

# define TETR_SIZE 4

typedef enum    e_err
{
    ERR = -1,
    END = 0,
    OK = 1
}               t_err;

void    deltetr(void *content, size_t content_size);
t_err   gettetr(int fd, char **tetr);
t_list  *gettetrlst(int fd);
void    puttetr(char *tetr);
void    puttetrlst(t_list *lst);

#endif