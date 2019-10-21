#include "libfi.h"

t_err   validate(const char *tetr)
{
    int ctr_nei;
    int ctr_pcs;
    int i;
    int j;

    ctr_nei = 0;
    ctr_pcs = 0;
    i = 0;
    while (i < TETR_SIZE)
    {
        j = 0;
        while (j < TETR_SIZE) {
            if (tetr[i * TETR_SIZE + j] == FILLED) {
                ++ctr_pcs;
                ctr_nei += (j > 0 && tetr[i * TETR_SIZE + (j - 1)] == FILLED);
                ctr_nei += (j < TETR_SIZE - 1 && tetr[i * TETR_SIZE + (j + 1)] == FILLED);
                ctr_nei += (i > 0 && tetr[(i - 1) * TETR_SIZE + j] == FILLED);
                ctr_nei += (i < TETR_SIZE - 1 && tetr[(i + 1) * TETR_SIZE + j] == FILLED);
            } else if (tetr[i * TETR_SIZE + j] != EMPTY)
                return (ERR);
            ++j;
        }
        ++i;
    }
    return (ctr_nei >= 6 && ctr_pcs == 4 ? OK : ERR);
}