
/**
 * Sets the seed for the Random Number Generator to the given
 *  seed, use this instead of trc_set_RNG_random_seed if you
 *  want control over what seed is being used (useful for
 *  testing and replicate states)
 *
 * @note Run only ONCE at the start of the program
 */
void trc_set_RNG_seed(int seed);

/***
 * Sets the Random Number Generator a random seed, so
 *  every time the game starts it generates new numbers
 *
 * @note Run only ONCE at the start of the program
 */
void trc_set_RNG_random_seed(void);

/**
 * Returns a random integer between the given range (both values included)
 *
 * @param min The minimum value for the random range
 * @param max The upper limit of the random range
 */
int trc_random_int(int min, int max);

