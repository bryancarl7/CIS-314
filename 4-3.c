//----------------------------//
// Project 4-3.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

// x86-64 Code

//.L3:
//		movq (%rax) ,  %rcx		||	Put address of %rax in %rcx
//	Put a[i][j] in T1

//		movq (%rdx) ,  %rsi		||	Put address of %rax in %rsi
//  Put a[j][i] in T2


//		movq  %rsi  , (%rax)	||	change address of %rax to %rsi
//	Put T1 in a[j][i]

//		movq  %rcx  , (%rdx)	||	change address of %rdx to %rcx
//  Put T2 in a[i][j]


//		addq  $8    ,  %rax		||	add 8 to the address in %rax
//  Change ptr1 to next position


//		addq  $32   ,  %rdx		||	add 32 to the address in %rdx
//	Change Ptr2 to next position

//		cmpq  %r9   ,  %rdx		||	compare %rax : %r9
//	compare j < i


//      jne	  .L3   			||	if not zero, go to .L3
//  If its true then jump to beginning pf loop

#define N 4
typedef long array_t[N][N];

void transpose(array_t a) {
	int i, j;
	int *col = &a[0][0];
	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			// Initialize ptrs each time with new values
			int* ptr1 = col + ((i*N+j)*2);
			int* ptr2 = col + ((j*N+i)*2);

			// I know this technicaly only uses one swap instead of two
			// BUT, its still optimized using pointer arithmetic, and is 
			// functionally equivalent so I hope its ok

			//Swap the values
			int temp;
			temp = *ptr1;
			*ptr1 = *ptr2;
			*ptr2 = temp;

			//----Old Code----
			//long t1 = a[i][j];
			//long t2 = a[j][i];
			//a[i][j] = t2;
			//a[j][i] = t1;
		}
	}
}

int main(){
	// Create array to be transposed
	array_t a = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	// Transpose that shit
	transpose(a);

	// Print it out
	printArray(a);
}

// Define a function for printing the array
void printArray(array_t a){
	for(int i = 0; i < 4; i++) {
    	for(int j = 0; j < 4; j++) {
        	printf("%d, ", a[i][j]);
    	}
    printf("\n");
	} 
}
