// Author:	Andrew Graham
// Date: 		18 August 2015
// Purpose:	Simple exercise to express what pointer notation means

#include <stdio.h>

int main(void) {

	int *ip;	// A pointer to an int object
	int a;
	
	a = 5;
	ip = &a;	// Assign the address of 'a' to ip
	
	printf("a:   %d\n", a);		// The value of 'a'
	printf("&a:  %d\n", &a);	// The address of 'a'
	printf("*ip: %d\n", *ip); // The value of the object that '*ip' points to
	printf("ip:  %d\n", ip); 	// The address that 'ip' points to

	return 0;
	
}