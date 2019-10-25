#include "libfi.h"

void    deltetr(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}