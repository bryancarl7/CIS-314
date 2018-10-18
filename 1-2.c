//----------------------------//
// Project 1-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

//Prototypes are self explanitory
unsigned int combine(unsigned int x, unsigned int y);
void printBytes(unsigned char *start, int len);
void printInt(int x);

int main(){
	// The beautiful test cases
	unsigned int combined = combine(0x12345678, 0xABCDEF00);
	printf("Your first answer %X", combined);
	printf("\n0x1234EF00");
	unsigned int combined2 = combine(0xABCDEF00, 0x12345678);
	printf("\nYour second answer %X", combined2);
	printf("\n0xABCD5678");
	return 0;
}

unsigned int combine(unsigned int x, unsigned int y){
	// Creating masks to use for isolating bits
	unsigned int mask1 = 0x00;
	unsigned int mask2 = 0x00;

	// Begin taking the bytes apart
	unsigned int combine1 = (x >> 16) | mask1;
	unsigned int combine2 = (y << 16) | mask2;

	// Combine them back together and return
	unsigned int combine3 = combine1 << 16;
	unsigned int combine4 = combine2 >> 16;

	// Perhaps a little unecessary to shift them apart and then back
	// I just like this more than using pre-set masks
	unsigned int FUB = (combine3 | combine4);
	return FUB;
}
