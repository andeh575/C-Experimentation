// Author:	Andrew Graham
// Date:		17 August 2015
// Purpose:	Generates a simple table of temperature values in Celsius, Farenheit, and Kelvin
#include <stdio.h>

int main (void) {

	float fahr, cels, kelv;
	int i;
	int maximum = 30;
	
	fahr = 0;
	
	// Print the table header
	printf("%2c %5c %6c\n", 'F', 'C', 'K');
	printf("-----------------\n");
	
	for (i = 0; i <= maximum; i++)
	{	
		cels = (fahr - 32) / 1.8;
		
		kelv = cels + 273;
		
		printf("%3.f %6.1f %6.1f\n", fahr, cels, kelv);
		
		fahr = fahr + 10;
	}

	return 0;
}