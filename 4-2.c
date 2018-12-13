//----------------------------//
// Project 4-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

// ---------Original Code---------------------

// int sum (int from, int to) {
// 	int result = 0;
// 	do {
// 		result += from;
// 		++from;
// 	} while (from <= to);
// 	return result;
// }

//--------------------------------------------


// -------Code from the review session--------

//.LOOP: result += start
// --start;
// if (start)
//	goto .LOOP;
// return result

// movq $0, %rax
// .LOOP: addq %rdi, %rax
//		addq $-1, %rdi
//		jne .LOOP
//		ret

// -------------------------------------------


// Actual function, Comments included in Assembly
long sum(long from, long to) {
	long result = 0;
	// Ensure that argument *from* is in %rdi
	// argument *to* is in %rsi, *result* is in %rax - do not modify
	__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from )); 
	__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));

	//Your x86-64 code goes below - comment each instruction
	__asm__("movq $0, %rax   # this is going to initialize %rax to 0;");
	__asm__(".LOOP:          # Starting the loop;");
	__asm__("addq %rdi, %rax # This adds from to result;");
	__asm__("addq $1, %rdi   # increments from;");
	__asm__("cmpq %rsi, %rdi # now compare from:to;");
	__asm__("jle .LOOP       # Jump back to the loop is condition is met");

	// Ensure that *result* is in %rax for return -do not modify.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;
}

int main(){
	// Have some Tests to see if it runs
	long test1 = sum(1, 6);
	long test2 = sum(3, 5);

	// Print out results
	printf("%d! should be: 21\n", test1);
	printf("%d! should be: 12\n", test2);
}

