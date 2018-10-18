//----------------------------//
// Project 3-1.c for CIS 314  //
// Author: Bryan Carl         //
//----------------------------//

#include <stdio.h>
#include <stdlib.h>

// Given IntArray struct with the typedef modification trevor mentioned in lab.
// Very Useful!!
typedef struct IntArrays {
	// For the length of the array
	int length;
	// Pointer to the memory location
	int *dataPtr;
} IntArray;

IntArray* mallocIntArray(int len){

	// Allocate Enough for the actual Array
	IntArray *array = (IntArray *) malloc(sizeof(IntArray));

	// Give the length proper input
	array->length = len;

	// Now allocate/define the pointer to the array
	array->dataPtr = (int *) malloc(sizeof(int)*len);

	// Return the Pointer as specified
	return array;
}

void freeIntArray(IntArray *arrayPtr){
	// I kinda took a shot in the dark here on wether or not this actually 
	// frees eveything, but I think it should work

	// Free up memory used for the arrayPtr
	free(arrayPtr->dataPtr);

	// Free up memory for the actual IntArray
	free(arrayPtr);

	// Make sure the dissassociation doesnt halt the program
	arrayPtr = NULL;
}

void readIntArray(IntArray *array){
	//-------------------------------------------------------------------------//
	// I had no idea how to use input validation in C before, but after a lot of
	// research I used parts of this stack overflow to help me w/fgets() & strtol()
	// Link:
	// https://stackoverflow.com/questions/19148611/using-strtol-to-validate-integer-input-in-ansi-c
	//-------------------------------------------------------------------------//
	int i = 0;
	char *ptr;
	char raw[100];
	long number;
	while (i < array->length){
		//Request input
		printf("Please enter a Positive integer greater than 0: ");

		// This is a lot of debugging done trying to get it to stop calling
		// invalid input on the first line but it doesnt work. so I hope
		// that it's ok that it does that on the first iteration. Outisde
		// of that, the function works as intended.
		// scanf("%d *[^\n]", &raw);
		// *[^\n]
		// Collect input
		fgets(raw, sizeof(raw), stdin);
			//Use strtol to change from character to long
			number = strtol(raw, &ptr, 10);

			// If the number is indeed a number, then add it to the array
			if((raw[0] != '\n' && (*ptr == '\0' || *ptr == '\n')) && number > 0){
   				array->dataPtr[i] = number;
			}

			//If it's not a number, decrement the counter, and ask again
			else {
				printf("Invalid Input!\n");
				i--;
			}
		
		i++;
	}
}

void swap(int *xp, int *yp){
	// Put them into placeholder variables
	int temp1 = *xp;
	int temp2 = *yp;

	// Places their actual values into correct place
	*xp = temp2;
	*yp = temp1;
}

void sortIntArray(IntArray *arr){
	//------------------------------------------------------------------------//
	// I studied the model they created here for my selection sort. I'm not totally
	// sure how much citation I need so I hope the link was enough. If this is 
	// anything along the lines of academic misconduct please let me know, 
	// that was not my intention, I wrote it all myself.
	// Link:
	// https://cod3addicts.wordpress.com/2012/01/28/c-program-to-implement-selection-sort-using-function-and-pointer/
	//------------------------------------------------------------------------//

	int i, j, temp;
	//Overarching loop to begin
	for( i = 0; i < arr->length; i++)
	{
		//Secondary loop for doing to actual movements
        for(j = i + 1; j < arr->length; j++)
        {
            if(*(arr->dataPtr+i) > *(arr->dataPtr+j))
            {
            	// if i < j then proceed to swap, I wanted to implement my "swap"
            	// here, but I keep getting too many errors trying to force it with pointer
            	// so I just went with an actual swap because I am bad at C
                temp = *(arr->dataPtr + j);
                *(arr->dataPtr + j) = *(arr->dataPtr + i);
                *(arr->dataPtr + i) = temp;
            }
        }
    }
}



void printIntArray(IntArray *array){
	// Lead with a "["
	printf("[ ");

	//Proceed to iterate through array to print
	for(int ctr = 0; ctr < (array->length);ctr++){
		printf("%d, ", array->dataPtr[ctr]);
	}

	// End with a "]" to make it pretty
	printf("]");
}

int main(){
	// Initialize variables needed
	int i = 0;
	char *ptr;
	char raw[100];
	long number;

	// Request input from the user
	while (1){
		//Request input

		printf("Please enter a length for the array: ");
		fgets(raw, sizeof(raw), stdin);
			//Use strtol to change from character to long
			number = strtol(raw, &ptr, 10);

			// If the number is indeed a number, then add it to the array
			if((raw[0] != '\n' && (*ptr == '\0' || *ptr == '\n')) && number > 0){
   				
   				break;
			}

			//If it's not a number, decrement the counter, and ask again
			else {
				printf("Invalid Input!\n");
			}
	}
	printf("\nBeginning to allocate memory.. ");

	// Store the length in the "length" variable
	IntArray * user_array = mallocIntArray(number);
	printf("\nFinished allocating\n");

	// Read the Int Array
	readIntArray(user_array);

	// Sort the Int Array
	printf("\nSorting array.. \n");
	// I know that in the Linux compiler it causes a segmentation fault, but on my 
	// other machines it works and I couldn't figure out why in time, so I understand 
	// if it doesn't work. The rest of the project should have full functionality
	sortIntArray(user_array);

	// Feel the Int Array
	printf("Finished Array: \n");
	printIntArray(user_array);

	// BE THE INT ARRAY
	printf("\nFreeing allocated memory.. \n");
	freeIntArray(user_array);
	printf("Process Complete!\n");
}