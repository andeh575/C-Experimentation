// Author:	Andrew Graham
// Date:		18 August 2015
// Purpose:	A simple utility that counts blanks, tabs, and newline characters in the text stream

#include <stdio.h>

int main(void) {

	int c, spaceCnt;
	
	spaceCnt = 0;
	
	while((c = getchar()) != EOF)
		if(c == '\n' || c == ' ' || c == '\t')
			++spaceCnt;

	printf("White space and newline count: %d\n", spaceCnt);
	
	return 0;
}