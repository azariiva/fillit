#include "libfi.h"

//TODO: add validate in gettetr

static t_err  get_frstpos(char *line, int *frst)
{
    int i;

    i = 0;
    while (i < TETR_SIZE)
    {
        if (line[i] == FILLED)
        {
            if (*frst == -1 || *frst > i)
                *frst = i;
            return (OK);
        }
        ++i;
    }
    return (ERR);
}

static void  get_lastpos(char *line, int *last)
{
    int i;

    i = 0;
    while (i < TETR_SIZE)
    {
        if (line[i] == FILLED)
        {
            if (*last == -1 || *last < i)
                *last = i;
        }
        ++i;
    }
}

t_err       gettetr(int fd, t_tetr *tetr)
{
    int i;
    int h_begin;
    int h_end;
    int w_begin;
    int w_end;

    i = 0;
    h_begin = -1;
    w_begin = -1;
    w_end = -1;
    while (i < TETR_SIZE)
    {
        if (read(fd, tetr->body + i * TETR_SIZE, TETR_SIZE) != TETR_SIZE)
            return (ERR);
        if (get_frstpos(tetr->body + i * TETR_SIZE, &w_begin) == OK)
        {
            if (h_begin == -1)
            {
                h_begin = i;
                h_end = i;
            }
            else
                h_end = i;
            get_lastpos(tetr->body + i * TETR_SIZE, &w_end);
        }
        if (ft_getc(fd) != '\n')
            return (ERR);
        ++i;
    }
    if (w_begin != -1)
    {
        tetr->uleft.x = w_begin;
        tetr->uleft.y = h_begin;
        tetr->dright.x = w_end;
        tetr->dright.y = h_end;
    }
    if ((i = ft_getc(fd)) != '\n' && i)
        return (ERR);
    return (i ? OK : END);
}