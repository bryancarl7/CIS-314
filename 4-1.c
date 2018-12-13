//----------------------------//
// Project 4-1.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

// Begin the Translation from x86-64

// ACCORDING TO THE BOOK:
// a should be in %rdi and b should be in %rsi

//loop:
//	movq  %rsi, %rcx
// Make b stored in alternate register to use

//	movl  $1, %edx  -  (Bytes 5-8 of %rdx)
// Setting the mask equal to 1

//	movl  $0, %eax  -  (Bytes 5-8 of %rax)
// Setting result equal to 0

//.L2
//	testq %rdx, %rdx
// Had to do a bit of research for this one, its a test to see if it isnt 
// equal to zero, so the code will jump to return if it is equal to zero

//	je	  .L4
// jumping if it is not equal 

//	movq  %rdx, %r8
// Moving the mask to register r8

//	andq  %rdi, %r8
// Bitwise and to combine a and mask

//	orq   %r8, %rax
// Then or result and the "AND" final

//	salq  %cl, %rdx
// Arithmetic shift left rdx however much the %cl value is

//	jmp	  .L2

//.L4
//	ret

long loop(long a, long b) {
	long result = 0;
	for (long mask = 1; mask != 0; mask <<= b){
		result |= (a & mask);
	}
	return result;
}

int main(){
	// Write some test cases for the kids
	long test1 = loop(1, 5);
	long test2 = loop(2, 4);
	long test3 = loop(3, 3);
	long test4 = loop(4, 2);
	long test5 = loop(5, 1);

	// PRINT em out
	printf("%d! should be: 1\n", test1);
	printf("%d! should be: 0\n", test2);
	printf("%d! should be: 1\n", test3);
	printf("%d! should be: 4\n", test4);
	printf("%d! should be: 5\n", test5);
}