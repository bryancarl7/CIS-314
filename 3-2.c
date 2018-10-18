//----------------------------//
// Project 3-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

long decode(long a, long b, long c){
	// This is all for decoding purposes

	// a -> %rdi
	// b -> %rsi
	// c -> %rdx

	// func -> Src, Dest | {Dest = Dest (func) Src}

	// Instructions:
	// subq %rdx, %rsi
	// imulq %rsi, %rdi
	// salq $63, %rsi
	// sarq $63, %rsi
	// movq %rdi, %rax
	// xorq %rsi, %rax

	// A lot of time went into reverse calculating this. I hope I didnt 
	// confuse any of the sources/destinations.
	long exit;

	// subq %rdx, %rsi
    b -= c;

    // imulq %rsi, %rdi
    a *= b;

    // Move to return address
    exit = a;

    // salq $63, %rsi
    exit <<= 63;

    // sarq $63, %rsi
    exit >>= 63;

    // movq %rdi, %rax
    exit ^= a;

    // xorq %rsi, %rax
    return exit;
}

int main(){
	// Define variables for testing
	int one, two, three;

	// Execute functions/Store values
	one = decode(1,2,4);
	two = decode(3,5,7);
	three = decode(10,20,30);

	// Print block
	printf("%d\n", one);
	printf("%d\n", two);
	printf("%d\n", three);
}