/* Author:	Andrew Graham
/	 Date:		18 August 2015
/	 Purpose:	A simple program that mimics the behavior of the UNIX command: wc
/						It produces a count of lines, words, and characters. A word is loosely
/						defined as any sequence of characters that does not contain:
/						
/										' ', '\t', or '\n'
*/

#include <stdio.h>
#include <stdbool.h>	// Standard in C99

int main(void) {
	
	int c, lineCnt, wordCnt, charCnt;
	bool word;
	
	lineCnt = wordCnt = charCnt = 0;
	word = false;
	
	while((c = getchar()) != EOF) {
		++charCnt;
		if(c == '\n')
			++lineCnt;
		if(c == ' ' || c == '\t' || c == '\n') // We've dropped off a word
			word = false;
		else if (!word) {		// Encountered first character of a word - let's count it
			word = true;
			++wordCnt;
		}
	}
	
	printf("Lines: %d; Words: %d; Characters: %d\n", lineCnt, wordCnt, charCnt);

	return 0;
}