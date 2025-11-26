
/**
 * Sets the seed for the Random Number Generator
 *
 * @note Run only once at the start of the program
 */
void trc_set_random_seed(int seed);

/**
 * Returns a random integer between the given range (both values included)
 *
 * @param min The minimum value for the random range
 * @param max The upper limit of the random range
 */
int trc_random_int(int min, int max);

