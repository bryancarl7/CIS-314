//----------------------------//
// Project 6-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Original untouched looop
void inner(float *u, float *v, int length, float *dest){
	int i;
	float sum = 0.0f;
	for (i = 0; i < length;++i){
		sum += u[i]*v[i];
	}
	*dest = sum;
}

// New Enhanced loop
void inner2(float *u, float *v, int length, float *dest){
	int i, sum0=0,sum1=0,sum2=0,sum3=0;
	float sum = 0.0f;
	for (i = 0; i < length;i+=4){
		// Splits them all up, doing 4x loop unrolling with accumulators
		sum0 = sum0 + u[i] * v[i];
		sum1 = sum1 + u[i+1] * v[i+1];
		sum2 = sum2 + u[i+2] * v[i+2];
		sum3 = sum3 + u[i+3] * v[i+3];
	}

	// Catch any missing elemets
	for (;i < length;i++){
		sum0 = sum0 + u[i] * v[i];
	}
	// Sum it all together in the end
	*dest = sum0+sum1+sum2+sum3;
}

int main(int argc, char** argv) {
	// Declare time variables for later assignment
	// Stole this from your lab demo, had no idea you could do this
	int Len = atoi(argv[1]);
	clock_t start;
	clock_t end;
	double total_time;
	float *dest = malloc(sizeof(float));

	// Pre-define a couple of arrays
	float *array1 = malloc(sizeof(float)*Len);
	float *array2 = malloc(sizeof(float)*Len);

	for (int i = 0; i < Len-1;i++){
		array1[i] = 1.0f;
	}

	// Clock the first unoptomized array
	start = clock();
	inner(array1, array2, Len, dest);
	end = clock();

	// Report time along with math for time
	total_time = ((double)(end - start))/ CLOCKS_PER_SEC;
	printf("TIME (UnOptimized): %f seconds. \n", total_time);

	// Clock the second optomized array
	start = clock();
	inner2(array1, array2, Len, dest);
	end = clock();

	// Report time along with math for time
	total_time = ((double)(end - start))/ CLOCKS_PER_SEC;
	printf("TIME (Optimized): %f seconds. \n", total_time);
	free(array1);
	free(array2);
}
