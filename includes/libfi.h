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
	char    color;
	t_coord uleft;
	t_coord dright;
}               t_tetr;

typedef struct  s_field
{
	char    **body;
	int     size;
	int     realsize;
}               t_field;

// DEBUG PURPOSE ONLY
void    printtetr(t_tetr *tetr);
void    printtetrlst(t_list *lst);

void    deltetr(void *content, size_t content_size);
t_list  *gettetrlst(int fd);

t_err   puttetrlst(t_list *lst, t_field *map);

#endif