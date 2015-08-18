// Author:	Andrew Graham
// Date:		18 August 2015
// Purpose:	A new version of the temperature program that utilitizes a function call.

#include <stdio.h>

double cels, kelv;

void tempConverter(double fahr);	


int main(void) {

	double fahr;
	
	// Print the table header
	printf("%2c %5c %6c\n", 'F', 'C', 'K');
	printf("-----------------\n");
	
	// Temperatures in increments of 10 degrees Fahrenheit up to 300
	for(fahr = 0; fahr <= 300; fahr += 10) {
		tempConverter(fahr);
		}

	return 0;
}

// Receive input as degrees Fahrenheit and output corresponding temperatures in Celsius and Kelvin
void tempConverter(double fahr) {

	cels = (fahr - 32) / 1.8;	
	kelv = cels + 273;
		
	printf("%3.f %6.1f %6.1f\n", fahr, cels, kelv);

	return;
}