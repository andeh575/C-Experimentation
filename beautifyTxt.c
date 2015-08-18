// Author:	Andrew Graham
// Date:		18 August 2015
// Purpose:	Beautify a text stream by eliminating extra ' ' or '\t' down to one of either

#include <stdio.h>

int main(void) {

	int c, spaceCnt;
	
	spaceCnt = 0;
	
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t') {		// Check for white space
			++spaceCnt;
			if(spaceCnt <= 1)						// If the white space is excessive, let's just ignore it!
				putchar(c);
		}
		else {
			putchar(c);		// We're okay with printing everything else!
			spaceCnt = 0;	// But let's make sure to reset the spaceCnt too!
		}
	}
			
	return 0;
}