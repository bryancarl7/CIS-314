//----------------------------//
// Project 2-2.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

unsigned int extract(unsigned int x, int i){
	// Use bit-shifting to multiply by 8
	int shiphturRight = i << 3;

	//Creating second shift variable to fix the other side 
	int shiphturLeft = 24 - shiphturRight;

	// Shift word left to "shake off" bits we dont want
	x <<= shiphturLeft;
	x >>= shiphturLeft;

	// Shift word right to  have a similar effect
	x >>= shiphturRight;

	// I know that this is kind of lazy/unoriginal, but I like it.
	// Return your new word
	return x; 
	//Again this returns an int, which is less than ideal, but on the back-end it works
}

int main(){
	//Two quick lines for testing
	unsigned int one = extract(0x12345678, 0);
	unsigned int two = extract(0xABCDEF00, 2);

	//Print statements
	printf("%d\n", one);
	printf("%d\n", two);

	//exit
	return 0;
}