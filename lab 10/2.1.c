#include <stdio.h>
 #include <string.h>
 #define MAX_FLIGHTS 100
 typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
 } Flight;
 Flight flights[MAX_FLIGHTS];
 int flightCount = 0;
 void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        printf("Cannot add more flights. Maximum limit reached.\n");
        return;
    }
    printf("\n--- Add a New Flight ---\n");
    printf("Enter flight number: ");
    scanf("%d", &flights[flightCount].flightNumber);
    getchar(); 
    printf("Enter departure city: ");
    fgets(flights[flightCount].departureCity, sizeof(flights[flightCount].departureCity), stdin);
    flights[flightCount].departureCity[strcspn(flights[flightCount].departureCity, "\n")] = '\0';
    printf("Enter destination city: ");
    fgets(flights[flightCount].destinationCity, sizeof(flights[flightCount].destinationCity), stdin);
    flights[flightCount].destinationCity[strcspn(flights[flightCount].destinationCity, "\n")] = '\0';
    printf("Enter date (DD/MM/YYYY): ");
    fgets(flights[flightCount].date, sizeof(flights[flightCount].date), stdin);
    flights[flightCount].date[strcspn(flights[flightCount].date, "\n")] = '\0';
    printf("Enter available seats: ");
    scanf("%d", &flights[flightCount].availableSeats);
    flightCount++;
    printf("Flight added successfully!\n");
 }
 void displayFlights() {
 	int i;
    if (flightCount == 0) {
        printf("\nNo flights available.\n");
        return;
    }
    printf("\n--- Available Flights ---\n");
    for (i = 0; i < flightCount; i++) {
        printf("\nFlight Number: %d\n", flights[i].flightNumber);
        printf("Departure City: %s\n", flights[i].departureCity);
        printf("Destination City: %s\n", flights[i].destinationCity);
        printf("Date: %s\n", flights[i].date);
        printf("Available Seats: %d\n", flights[i].availableSeats);
    }
 }
 void bookSeat() {
    if (flightCount == 0) {
        printf("\nNo flights available to book.\n");
        return;
    }
    int flightNumber, i;
    printf("\n--- Book a Seat ---\n");
    printf("Enter flight number to book a seat: ");
    scanf("%d", &flightNumber);
    for (i = 0; i < flightCount; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully! Remaining seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available on this flight.\n");
            }
            return;
        }
    }
    printf("Flight not found.\n");
 }
 int main() {
    int choice;
    do {
        printf("\n--- Flight Management System ---\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Book Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                displayFlights();
                break;
            case 3:
                bookSeat();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
 }
