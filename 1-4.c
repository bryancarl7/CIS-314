//----------------------------//
// Project 1-4.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

//Prototypes are self explanitory
int oddBit(unsigned int x);

int main() {
	// All the pretty test cases
	unsigned int odd1 = oddBit(0x1);
	printf("Test Case 1: %x\n",odd1);
	unsigned int odd2 = oddBit(0x2);
	printf("Test Case 2: %x\n",odd2);
	unsigned int odd3 = oddBit(0x3);
	printf("Test Case 3: %x\n",odd3);
	unsigned int odd4 = oddBit(0x4);
	printf("Test Case 4: %x\n",odd4);
	unsigned int odd5 = oddBit(0xFFFFFFFF);
	printf("Test Case 5: %x\n",odd5);
	unsigned int odd6 = oddBit(0xAAAAAAAA);
	printf("Test Case 6: %x\n",odd6);
	unsigned int odd7 = oddBit(0x55555555);
	printf("Test Case 7: %x\n",odd7);
	// Funny how the test cases are 10x longer than the actual solution
}

int oddBit(unsigned int x){
	// Create a mask to phase out the odd bits
	unsigned int baseline = 0xAAAAAAAA;

	// Use the AND to get only the bits we want
	unsigned int masked = x & baseline;

	// Hit em with DAT DOUBLE NEGATIVE
	return !!masked;
	// *High fives all around*
}