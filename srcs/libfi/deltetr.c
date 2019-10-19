#include "libfi.h"

void    deltetr(void *content, size_t content_size)
{
    size_t  i;

    if (content)
    {
        i = 0;
        while (i < content_size)
            ((char *) content)[i++] = 0;
        free(content);
    }
}