#ifndef LIBFI_H

# define LIBFI_H

# include "libft.h"

# define TETR_SIZE 4
# define FILLED '#'
# define EMPTY '.'

typedef enum    e_err
{
    ERR = -1,
    END = 0,
    OK = 1
}               t_err;

typedef struct  s_coord
{
    int x;
    int y;
}               t_coord;

typedef struct  s_tetr
{
    char    body[TETR_SIZE * TETR_SIZE];
    t_coord uleft;
    t_coord dright;
}               t_tetr;

typedef struct  s_field
{
    char    **field;
    int     size;
    int     realsize;
}               t_field;

void    deltetr(void *content, size_t content_size);
t_err   gettetr(int fd, t_tetr *tetr);
t_list  *gettetrlst(int fd);

t_err   validate(const char *tetr);
t_err   validatelst(t_list *lst);

void    printtetr(t_tetr *tetr);
void    printtetrlst(t_list *lst);

t_err   puttetr(t_tetr *tetr, t_field *map, t_coord place);
t_err   puttetrlst(t_list *lst, t_field *map);

#endif