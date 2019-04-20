#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "bitvector.h"

// Returns number between 0 and 1 inclusive
double rand_param() {
    return ((double)rand() / (double)RAND_MAX);
}

// Param: characteristic vectore of B
// Returns: cardinality of missing sums of B
int count_missing(bitvector B, uint8_t n) {
    uint8_t count = 0;
    for (uint8_t i = 0; i < n; i++) {
        if (!bitvector_get(B, i)) count++;
    }
    return count;
}

// Generate subset of [0, 1, ... , n]
// Probability of an element being contained is p
// Param: probability p, number of elements n
// Returns: characteristic vector of subset
bitvector gen_set(double p, index n) {
    bitvector new = bitvector_new();
    for (index i = 0; i < n; i++) {
        if (rand_param() < p) {
            new = bitvector_flip(new, i);
        }
    }
    return new;
}


// Compute Sumset
// Param: characteristic vectore of B
// Returns: characterictic vector of B+B
bitvector sumset(bitvector A, bitvector B) {
    bitvector sum = bitvector_new();
    bitvector check = bitvector_new();
    for (index i = 0; i < BITVECTOR_LIMIT/2; i++) {
        if (bitvector_get(A, i)) {
            for (index j = 0; j < BITVECTOR_LIMIT/2; j++) {
                if (bitvector_get(B, j) && !bitvector_get(check, i + j)) {
                    sum = bitvector_flip(sum, i + j);
                    check = bitvector_flip(check, i + j);
                }
            }
        }
    }
    return B;
}

// Compute Sumset of a Sumset
// Param: characteristic vector of B
// Returns: characteristic vector of B+B+B+B
bitvector sumset_of_sumset(bitvector B) {
    bitvector sum = sumset(B, B);
    return sumset(sum, sum);
}

// Simulate

//int[] simulate(bitvector B, uint8_t k) {
    
//}


int main() {
    bitvector n = gen_set(0.5, 20);
    for (index i = 0; i < 5; i++) {
        bool b = bitvector_get(n, i);
        fprintf(stdout, "%d\n", b);
    }
    fprintf(stdout, "%d\n", count_missing(n, 5));
    return 0;
}
