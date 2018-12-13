//----------------------------//
// Project 7-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

// This seems fairly straightforward, but I'm very concerned I 
// misunderstood the assignment
unsigned int getOffset(unsigned int address){
	// I'm lazy so I'm just gunna "shake off" the bits I don't want
	address <<= 28;

	// Shaking off the other bits
	address >>= 28;

	// return it back
	return address;
}

unsigned int getSet(unsigned int address){
	// Shake off the ending bits
	address <<= 24;

	// Push all the way over to only keep the second byte
	address >>= 28;

	// Return the word back
	return address;
}

unsigned int getTag(unsigned int address){
	// Shift the bits over so that you have just the tag
	address >>= 8;

	// return the tag
	return address;
}

int main() {
	// All the pretty and formatted unit tests
	// This is for loading the function values into variable
	unsigned int offset = getOffset(0x12345678);
	unsigned int set = getSet(0x12345678);
	unsigned int tag = getTag(0x12345678);

	// Print them out to make sure they work
	printf("\n0x12345678: offset: %X - ", offset);
	printf("tag: %X - ", tag);
	printf("set: %X\n", set);


	// Test on multiple value for maximum value
	unsigned int offset2 = getOffset(0x87654321);
	unsigned int set2 = getSet(0x87654321);
	unsigned int tag2 = getTag(0x87654321);

	// Second print stack
	printf("\n0x12345678: offset: %X - ", offset2);
	printf("tag: %X - ", tag2);
	printf("set: %X\n", set2);

	return 0;
}
