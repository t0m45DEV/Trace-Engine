#include "trc_random.h"

#include <stdlib.h>
#include <time.h>

void trc_set_RNG_seed(int seed)
{
    srand(seed);
}

void trc_set_RNG_random_seed(void)
{
    trc_set_RNG_seed(time(NULL));
}

int trc_random_int(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

