//----------------------------//
// Project 2-3.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>


int ge(float x, float y){
	unsigned int ux = *((unsigned int*)&x);// convert x raw bits
	unsigned int uy = *((unsigned int*)&y);// convert y raw bits
	unsigned int sx = ux >> 31;// extract sign bit of ux
	unsigned int sy = uy >> 31;// extract sign bit of uy    
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy

	// Wow this took a lot longer than I thought it would

	// To break it down simply on either side of the OR:
	// -The left side says return true if x is greater than or equal to y (signed)
	// -The right side says to ignore negative zeroes
	return (((sx <= sy)&&(ux >= uy))||(ux==0 && uy==0));
	// The test cases worked for me so I hope my solution is ok.
}

int main(){
	// A couple quick lines for testing
	unsigned int one = ge(0.0f, 0.0f);
	unsigned int two = ge(-0.0f, 0.0f);
	unsigned int three = ge(-1.0f, 0.0f);
	unsigned int four = ge(0.0f, 1.0f);
	unsigned int five = ge(1.0f, 0.0f);

	//Print statements
	printf("%d\n", one);
	printf("%d\n", two);
	printf("%d\n", three);
	printf("%d\n", four);
	printf("%d\n", five);

	//exit
	return 0;
}