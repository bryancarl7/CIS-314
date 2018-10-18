//----------------------------//
// Project 1-1.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

//Prototypes are self explanitory
void printBytes(unsigned char *start, int len);
void printInt(int x);
void printFloat(float x);
void printDouble(double x);
void printShort(short x);
void printLong(long x);

int main() {
	// A couple short stubs to make sure it works
	printLong(10.12);
	printShort(12);
	printDouble(10.45);
	return 0;
}

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char*) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char*) &x, sizeof(float));
}

// Should be fairly self explanitory
void printShort(short x) {
	printBytes((unsigned char*) &x, sizeof(short));
}

// Just changing the size and type as necessary
void printLong(long x) {
	printBytes((unsigned char*) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char*) &x, sizeof(double));
}