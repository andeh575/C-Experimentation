// Author:	Andrew Graham
// Date:	18 August 2015
// Purpose:	A simple demonstration of the struct datastructure

#include <stdio.h>
#include <stdlib.h>	// Needed for malloc()
#include <string.h> // Needed for strcpy()

typedef struct flightData Fighter; // A short hand to represent the struct flightData

// Tells the compiler the size and specifications of the struct but does not allocate memory
struct flightData {
	char flight[7];
	int altitude;		// meters
	int latitude;		// tenths of degrees
	int longitude;		// tenths of degrees
	int heading;		// tenths of degrees
	double airSpeed;	// km/hr
};

void addAircraft(Fighter m[], int n);		// Array access is always indirect in C
void displayAircraft(Fighter m[], int n);

int main(void) {

	int airborneFighters, i;
	Fighter *fighters;
	
	printf("How many fighters are deployed?\n");
	scanf("%d", &airborneFighters);
	
	// Allocating memory for active aircraft deployed
	fighters = (Fighter*) malloc(sizeof(Fighter) * airborneFighters);
	if(fighters == NULL)
		printf("Error during memory allocation\n");
		
	addAircraft(fighters, airborneFighters);
	displayAircraft(fighters, airborneFighters);
	
	// Free memory allocated by malloc()
	free(fighters);
	
	return 0;
}

// Function to add fighters the array of struct
void addAircraft(Fighter fighters[], int airborneFighters) {
	int i;
	char flight[7];
	
	// Begin filling in data for each allocated fighter
	printf("Beginning Data Entry for [%d] Fighters...\n\n", airborneFighters);
	for(i = 0; i < airborneFighters; i++) {
		printf("\nFighter %d\n", i + 1);
		printf("------------\n");
		
		/* Current implementation does not check to correct input */
		printf("Flight ID (6 Characters Max): ");
		scanf("%s", flight);
		strcpy(fighters[i].flight, flight);
		
		printf("Altitude (meters): ");
		scanf("%d", &fighters[i].altitude);
		
		printf("Latitude (tenths of degrees): ");
		scanf("%d", &fighters[i].latitude);
		
		printf("Longitude (tenths of degrees): ");
		scanf("%d", &fighters[i].longitude);
		
		printf("Heading (tenths of degrees): ");
		scanf("%d", &fighters[i].heading);
		
		printf("Air Speed (km/hr): ");
		scanf("%lf", &fighters[i].airSpeed);
	}
	
	return;
}

// Function to display the array of struct
void displayAircraft(Fighter fighters[], int airborneFighters) {
	int i;

	printf("\nDisplaying deployed fighters...\n\n");
	for(i = 0; i < airborneFighters; i++) {
		printf("Fighter [%d] -- FlightID: %s\n", i + 1, fighters[i].flight);
		printf("Altitude: %d m\n", fighters[i].altitude);
		printf("Latitude: %d deg.; Longitude: %d deg.\n", fighters[i].latitude, fighters[i].longitude);
		printf("Heading: %d deg.; Air Speed: %.2f km/hr\n\n", fighters[i].heading, fighters[i].airSpeed);	
	}
	
	return;
}