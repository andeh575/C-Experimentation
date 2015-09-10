/*	Author:		Andrew Graham
/		Date:			18 August 2015
/		Purpose:	This program is a simple ASCII calculator that uses reverse Polish notation.
/
/							EX:	(1 + 2) * (5 - 3)  =>  1 2 + 5 3 - *
*/

#include <stdio.h>

void push(double f);	
double pop(void);
int getOp(char s[]);

int main(void) {
	
	double c, op2;
	
	while((c = getchar()) != EOF) {
		switch(c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				push(c);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: Zero as a Denominator\n");
				break;
			default:
				break;
		}
	}
}

#define MAXVAL 100	// Maximum depth of stack

int sPos = 0;				// Stack index
double val[MAXVAL];	// Stack

// Push 'f' onto the stack
void push(double f) {
	if(sPos < MAXVAL)
		val[sPos++] = f;
	else {
		printf("Error: Stack full, can't push %g\n", f);
		return;
	}
}

// Pop 'f' off of the stack and return its value
double pop(void) {
	if(sPos > 0)
		return val[--sPos];
	else {
		printf("Error: Stack Empty\n");
		return;
	}
}

int getOp(char s[]) {

}