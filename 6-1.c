//----------------------------//
// Project 6-1.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4
typedef int array_t[N][N];

int dim() {return N;}


// Clocked in at 0.000001 seconds
void f_opt(array_t a, int x, int y) {
	for (int i = 0; i < dim(); ++i) {
		// Use optimized multiplication to make faster
		int j = 0;
		int ixy = i*x*y+j;
		// Much more effecient to do operation once for each loop
		// Could increase optimization further by calculating even further outside

		for (int j = 0; j < dim(); ++j){
			a[i][j] = ixy; 
		}
	} 
}

// Clocked in at 0.000002 seconds
void f_unopt(array_t a, int x, int y) {
	for (int i = 0; i < dim(); ++i) {
		for (int j = 0; j < dim(); ++j){
			// Very ineffecient to do manually each iteration
			a[i][j] = i*x*y+j; 
		}
	} 
}

// HALFED the time. Unsure is this is applicable on a large scale
// but, the array multiplication has been optimized


int main() {
	//Declare time variables for later assignment
	clock_t start;
	clock_t end;
	double total_time;

	// Initialize array
	int array_t[N][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	// Clock the first unoptomized array
	start = clock();
	f_unopt(array_t, 5, 5);
	end = clock();

	// Report time along with math for time
	total_time = ((double)(end - start))/ CLOCKS_PER_SEC;
	printf("TIME (UnOptimized): %f seconds. \n", total_time);

	// Clock the second optomized array
	start = clock();
	f_opt(array_t, 5, 5);
	end = clock();

	// Report time along with math for time
	total_time = ((double)(end - start))/ CLOCKS_PER_SEC;
	printf("TIME (Optimized): %f seconds. \n", total_time);
}
