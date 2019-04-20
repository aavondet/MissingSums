#include <stdbool.h>
#include <stdint.h>

#ifndef _BITVECTOR_H_
#define _BITVECTOR_H_

// typedef _______ bitvector;
typedef uint64_t bitvector;
// typedef _____ index;
// Replace to uint16_t if you need bigger sets
typedef uint8_t index;

#define BITVECTOR_LIMIT 40

/* Get a new bitvector with everything set to 'false'. */
bitvector bitvector_new();

/* Get the ith bit of the bitvector n. */
bool bitvector_get(bitvector B, index i)
/*@requires 0 <= i < BITVECTOR_LIMIT; @*/ ;

/* Toggle the ith bit of the bitvector n, returning a new bitvector. */
/* The old bitvector remains unchanged. */
bitvector bitvector_flip(bitvector B, index i)
/*@requires 0 <= i < BITVECTOR_LIMIT; @*/ ;

/* Compare two bitvectors for equality. */
bool bitvector_equal(bitvector B1, bitvector B2);

#endif
