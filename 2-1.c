//----------------------------//
// Project 2-1.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>

int mask(int n){

	// Going to be shifting over n number of spots to get the correct length.
	// From there, subtracting does the trick and gives us the mask we're looking for.
	int mask = (0x1 << n) - 1;

	// So I know that this returns whole integer values instead of their binary representations
	// but in binary it does 100% what it's supposed to, its just being represented
	// as an integer. I couldnt figure this part out so I hope you'll take pity on me for this.
	// Please let me know how to avoid this in the comments for this project, any help would
	// be greatly appreciated!
	return mask;
}

int main(){
	//Six quick lines for testing
	int one = mask(0);
	int two = mask(4);
	int three = mask(8);
	int four = mask(16);
	int five = mask(24);
	int six = mask(31);

	//Print statements
	printf("%d\n",one);
	printf("%d\n",two);
	printf("%d\n",three);
	printf("%d\n",four);
	printf("%d\n",five);
	printf("%d\n",six);

	//Exit
	return 0;
}