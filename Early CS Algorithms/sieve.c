// Day 1 of 60LOCAD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int max, int v) {
	int *oneToMax = calloc( max+1, sizeof(int) ), i=1, j=1;
	int numberOfPrimes = 1;

	// Prep the array
	for(i = 0; i < max; i++) {
		oneToMax[i] = i;
	}
	
	// Run the sieve -- this is the first version, much slower than below
	// for(i = 2; i < max; i++) {
	// 	for(j = i; j * i < max; j++) {
	// 		oneToMax[j*i] = 1;
	// 	}
	// }
	
	// Run the sieve -- we know all evens aren't prime, excluding 2, so don't check them
	for(i = 3; j * i < sqrt(max); i+=2) {
		for(j = i; j * i < max; j+=2) {
			oneToMax[j*i] = 1;
			// printf("{j*i}: %2d * %2d -- %d\n", j, i, j*i);
		}
	}

	// Print the result
	// int rowLen = (int)sqrt(max);
	// if( v ) {
	// 	for(i = 0; j+i < max; i+=rowLen) {
	// 		for(j = 0; j+i < rowLen; j++) {
	// 			printf("[%d]", oneToMax[j+i]);
	// 		}
	// 		printf("\n");
	// 	}
	// }

	// Count the primes and print them out
	if( v ) printf("2, ");
	for(i = 1; i < max; i+=2) {
		if( oneToMax[i] != 1 ){
			numberOfPrimes++; 
			if( v ) printf("%d, ", oneToMax[i]);
		}
	}
	if( v ) printf("\n");		

	return numberOfPrimes;
}

// I was getting segfaults, this was to make sure I wasn't going crazy and forgetting how C works
void reallyBigArray(int s, int v) {
	int *arr = calloc(s, sizeof(int)), n, i;
	for(i = 0; i < s; i++) {
		n = arr[i];
		if( v ) printf("%d", n);
	}
}

int main(int argc, char ** argv) {
	int targetNumber = 100, v = 0;
	if(argc > 1) targetNumber = atoi( argv[1] );
	if(argc > 2) v = atoi( argv[2] );

	printf("Number of Primes -- %d\n", sieve(targetNumber, v));

	return 1; 
}