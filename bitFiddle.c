/* Author:	Andrew Graham
 * Date:	10 September 2015
 * Purpose:	A refresher on bits/bitwise operations in C.
 */
 
 #include <stdio.h>
 #include <stdint.h>
 
 int main(void) {
	
	int16_t a = 0;
	
	a++;				// 0000 0000 0000 0001: 	1
	a = ~a;				// 1111 1111 1111 1110: 	-2
	a++;				// 1111 1111 1111 1111: 	-1
	printf("%d\n", a);
	
	a = a | a << a;		// 1111 1111 1111 1111: 	-1
	a++;				// 0000 0000 0000 0000: 	0
	printf("%d\n", a);
	
	a++;				// 0000 0000 0000 0001:		1
	a = 2 & (a << a);	// 0000 0000 0000 0000:		0
	printf("%d\n", a);
	
	return 0;
 }