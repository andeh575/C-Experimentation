// Author:	Andrew Graham
// Date:		18 August 2015
// Purpose: A simple line counting utility - looks for '\n' in text stream

#include <stdio.h>

int main(void) {
	
	int c, lineCnt;
	
	lineCnt = 0;
	
	while((c = getchar()) != EOF)
		if(c == '\n')
			++lineCnt;
	
	printf("Number of Lines: %ld\n", lineCnt);

	return 0;
}