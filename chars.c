// Author:	Andrew Graham
// Date: 		18 August 2015
// Purpose: Simple character copying from a text stream

#include <stdio.h>

int main(void) {
	
	int c;	// Must use int IOT hold EOF or any other char
	
	printf("Value of EOF: %d\n", EOF); // Because curious. It's -1 if you were curious too. 
	
	while((c = getchar()) != EOF)
		putchar(c);
		
	return 0;
}