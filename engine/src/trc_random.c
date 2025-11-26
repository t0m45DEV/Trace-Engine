#include "trc_random.h"

#include <stdlib.h>

void trc_set_random_seed(int seed)
{
    srand(seed);
}

int trc_random_int(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

