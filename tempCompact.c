// Author:	Andrew Graham
// Date:		17 August 2015
// Purpose:	Generates a simple table of temperature values in Celsius, Farenheit, and Kelvin.
//					This iteration attempts to compactly solve the same problem with one variable. While
//					it's neat to see such a compacted form work, it's very muddled. 
#include <stdio.h>

int fahr;

int main(void) {
	
	// Print temperatures in Fahrenheit, Celsius, and Kelvin
	for(fahr = 0; fahr <= 300; fahr = fahr + 10) {
		printf("%3d %6.1f %6.1f\n", fahr, ((fahr - 32) / 1.8), ((fahr - 32) / 1.8) + 273);
	}
	
	return 0;
}

