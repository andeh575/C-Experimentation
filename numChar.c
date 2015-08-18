// Author:	Andrew Graham
// Date:		18 August 2015
// Purpose:	Counting chars: includes white space, newlines, etc. 

#include <stdio.h>

int main(void) {
					
	long numChar;	// Just incase we need the extra room
	
	numChar = 0;

	while(getchar() != EOF) // Use CTRL-D in terminal to signal EOF - cygwin64/UNIX/Linux
		++numChar;
	
	printf("Number of Characters: %ld\n", numChar);

	return 0;
}