/* Author:	Andrew Graham
/ Date:	18 August 2015
/ Purpose:	A linked-list variation of simpleAircraft.c
/
/			---------------		 ---------------	  ---------------
/			| DATA | NEXT | ---> | DATA | NEXT | ---> | DATA | NEXT | ---> NULL
/			---------------		 ---------------	  ---------------
*/

#include <stdio.h>
#include <stdlib.h> // Needed for malloc()
#include <string.h> // Needed for strcpy()

typedef struct flightData Fighter;

struct flightData {
	char flight[7];
	int altitude;				// meters
	int latitude;				// tenths of degrees
	int longitude;				// tenths of degrees
	int heading;				// tenths of degrees
	double airSpeed;			// km/hr
	struct flightData *next;	// The next node on the list
};

void scanList(Fighter *head, char m[]);
void addElement(Fighter *head, Fighter *m);
void removeElement(Fighter *head, char m[]);
Fighter* newAircraft(void);
void displayAircraft(Fighter *m);
void displayList(Fighter *head);

int main(void) {

	Fighter *fighter, *head;
	int airborneFighters, i;
	char tmp[7];
	
	// Create the head element
	head = (Fighter*)malloc(sizeof(Fighter));
	if(head == NULL)
		printf("Error allocating memory for new object");
	
	printf("How many fighters are deployed?\n");
	scanf("%d", &airborneFighters);
	
	for(i = 0; i < airborneFighters; i++) {
		fighter = newAircraft();
		addElement(head, fighter);
	}
	
	displayList(head);	
	
	printf("Search for an entry by flight ID: ");
	scanf("%s", &tmp);
	scanList(head, tmp);
	
	return 0;
}

// Function to iterate over the linked-list and display the entry
void scanList(Fighter *head, char val[]) {
	Fighter *current = head;
	
	printf("Scanning list for: %s\n", val);
	
	while(current->next != NULL) {
		if(strcmp(current->flight, val) == 0) {
			displayAircraft(current);
			return;
		}
		
		current = current->next;
	}
	
	printf("Entry does not exist in list.\n\n");
	return;
}

// Function to add an element to the linked-list
void addElement(Fighter *head, Fighter *fighter) {
	Fighter *current = head;
	
	// Find the last position of the linked-list
	while(current->next != NULL)
		current = current->next;
	
	// We've found the correct node so let's add our variables in
	strcpy(current->flight, fighter->flight);
	current->altitude = fighter->altitude;
	current->latitude = fighter->latitude;
	current->longitude = fighter->longitude;
	current->heading = fighter->heading;
	current->airSpeed = fighter->airSpeed;
	
	// Ensure the next node is prepared for an entry
	current->next = malloc(sizeof(Fighter));
	
}

// Function to remove an element from the linked-list
void removeElement(Fighter *head, char val[]) {
	Fighter *current = head;
	Fighter *temp = NULL;
	
	printf("Removing entry: %s\n", val);
	
	while(current->next != NULL) {
		if(strcmp(current->flight, val) == 0) {
			//delete that entry and reconnect the list 
			temp = current->next;
			return;
		}
		
		current = current->next;
	}
	
	printf("Entry does not exist in list. Nothing removed.\n\n");
	return;
}

// Function to initialize a new Fighter struct
Fighter* newAircraft(void) {
	
	char flight[7];
	Fighter *fighter;
	
	// Allocate memory for new Fighter
	fighter = (Fighter*)malloc(sizeof(Fighter));
	if(fighter == NULL)
		printf("Error allocating memory for new object");
	
	// Begin filling in data for each allocated fighter
	printf("Beginning Data Entry for Fighter...\n\n");
	printf("\nFighter \n");
	printf("------------\n");
		
	/* Current implementation does not check to correct input */
	printf("Flight ID (6 Characters Max): ");
	scanf("%s", flight);
	strcpy(fighter->flight, flight);
		
	printf("Altitude (meters): ");
	scanf("%d", &(fighter->altitude));
		
	printf("Latitude (tenths of degrees): ");
	scanf("%d", &(fighter->latitude));
		
	printf("Longitude (tenths of degrees): ");
	scanf("%d", &(fighter->longitude));
		
	printf("Heading (tenths of degrees): ");
	scanf("%d", &(fighter->heading));
		
	printf("Air Speed (km/hr): ");
	scanf("%lf", &(fighter->airSpeed));

	return fighter;
}

// Function to display the array of struct
void displayAircraft(Fighter *fighter) {

	printf("\n\nFlightID: %s\n", fighter->flight);
	printf("Altitude: %d m\n", fighter->altitude);
	printf("Latitude: %d deg.; Longitude: %d deg.\n", fighter->latitude, fighter->longitude);
	printf("Heading: %d deg.; Air Speed: %.2f km/hr\n\n", fighter->heading, fighter->airSpeed);	
	
	return;
}

// Function to display all entries in the linked-list
void displayList(Fighter *head) {
	Fighter *current = head;
	
	printf("Display all entries in list...\n\n");
	
	// Make sure we don't print the last, empty but allocated entry
	while (current->flight[0] != '\0') {
		displayAircraft(current);
		current = current->next;
	}
}







