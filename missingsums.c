#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "lib/bitvector.h"
#include "lib/xalloc.h"

// Returns number between 0 and 1 inclusive
double rand_param() {
    return ((double)rand() / (double)RAND_MAX);
}

// Counts number of 0's until n from a bitvector
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
// Param: probability p, upper bound n (inclusive)
// Returns: characteristic vector of subset
bitvector gen_set(double p, index n) {
    bitvector new = bitvector_new();
    for (index i = 0; i <= n; i++) {
        if (rand_param() < p) {
            new = bitvector_flip(new, i);
        }
    }
    return new;
}


// Compute Sumset
// Param: characteristic vectore of B
// Returns: characterictic vector of B+B
bitvector sumset(bitvector A, uint8_t a, bitvector B, uint8_t b) {
    bitvector sum = bitvector_new();
    bitvector check = bitvector_new();
    for (index i = 0; i <= a; i++) {
        if (bitvector_get(A, i)) {
            for (index j = 0; j <= b; j++) {
                if (bitvector_get(B, j) && !bitvector_get(check, i + j)) {
                    sum = bitvector_flip(sum, i + j);
                    check = bitvector_flip(check, i + j);
                }
            }
        }
    }
    return sum;
}

// Simulate
//
// Param: k where we are computing A^(k),
//        n is the upper bound of original set [0, 1, ..., n]
//        sample is the number of sumsets to compute,
//        p is the probability an element is in a subset
// Returns: Array with i-th index containing
//          number of sumsets missing i sums
char *simulate(uint8_t k, uint8_t n, size_t sample,
               double p) {
    char *missing = {0};
    for (size_t i = 0; i < sample; i++) {
        bitvector temp = gen_set(p, n);
        for (uint8_t j = 0; j < k; j++) {
            temp = sumset(temp, n, temp, n);
        }
        index miss = count_missing(temp, n * k);
        missing[miss] += 1;
    }
    return missing;
}


int main() {
    //testing
//    bitvector n = gen_set(0.5, 5);
//    for (index i = 0; i <= 5; i++) {
//        bool b = bitvector_get(n, i);
//        fprintf(stdout, "%d\n", b);
//    }
//    fprintf(stdout, "%d\n", count_missing(n, 5));
//    n = sumset(n, 5, n, 5);
//    for (index i = 0; i <= 10; i++) {
//        bool b = bitvector_get(n, i);
//        fprintf(stdout, "%d\n", b);
//    }
//    fprintf(stdout, "%d\n", count_missing(n,10));
    
    //small cases
    bitvector n = bitvector_new();
    
    return 0;
}
