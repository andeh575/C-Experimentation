// Author:	Andrew Graham
// Date:		17 August 2015
// Purpose:	Generates a simple table of temperature values in Celsius, Farenheit, and Kelvin
#include <stdio.h>

int main (void) {

	int fahr, cels, kelv, i;
	int maximum = 30;
	
	fahr = 0;
	
	for (i = 0; i <= maximum; i++)
	{	
		cels = (fahr - 32) / 1.8;
		
		kelv = cels + 273;
		
		printf("%3d %3d %3d\n", fahr, cels, kelv);
		
		fahr = fahr + 10;
	}

	return 0;
}