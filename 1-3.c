//----------------------------//
// Project 1-3.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

//Prototypes are self explanitory
unsigned int replace(unsigned int x, int i, unsigned char b);

int main() {
	// All the pretty and formatted unit tests
	unsigned int replaced = replace(0x12345678, 2, 0xAB);
	printf("Your answer: %X\n", replaced);
	printf("Expected: 12AB5678\n");
	unsigned int replaced2 = replace(0x12345678, 0, 0xAB);
	printf("Your answer: %X\n", replaced2);
	printf("Expected: 123456AB\n");
	return 0;
}


unsigned int replace(unsigned int x, int i, unsigned char b){
	// Recast this to avoid odd side-effects
	int n = b;

	// Use bit-shifting to multiply by 8
	int f = i << 3;

	// Put n in the right position for a 32-bit word
	n = n << f;

	// Create a mask to isolate the byte in b
	unsigned int mask = 0xFF << f;

	// Do some quick AND/OR's to align the bytes in one variable
	unsigned int partial = x & ~mask;
	unsigned int final = n | partial;
	return final;
}