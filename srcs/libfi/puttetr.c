#include "libfi.h"

t_err   puttetr(t_tetr *tetr, t_field *map, t_coord place)
{
    if (tetr && map && place.x != -1)
        return (OK);
    return (ERR);
}