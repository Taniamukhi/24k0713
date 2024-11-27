#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100
#define STRING_LENGTH 50

// Structure to hold travel package information
struct TravelPackage {
    char packageName[STRING_LENGTH];
    char destination[STRING_LENGTH];
    int duration;
    float cost;
    int availableSeats;
};

// Function to display available travel packages
void displayPackages(struct TravelPackage packages[], int count) {
	int i;
    if (count == 0) {
        printf("No packages available.\n");
        return;
    }
    for ( i = 0; i < count; i++) {
        printf("Package %d: %s\n", i + 1, packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n", packages[i].availableSeats);
        printf("--------------------------\n");
    }
}

// Function to book a package
void bookPackage(struct TravelPackage *package) {
    if (package->availableSeats > 0) {
        package->availableSeats--;
        printf("Booking successful for package: %s\n", package->packageName);
    } else {
        printf("No available seats for package: %s\n", package->packageName);
    }
}

// Main function
int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    while (1) {
        printf("\n1. Add Package\n");
        printf("2. Display Packages\n");
        printf("3. Book Package\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (packageCount < MAX_PACKAGES) {
                    // Clear the input buffer before reading strings
                    getchar(); // consume the newline left by scanf

                    // Input for package details
                    printf("Enter package name: ");
                    fgets(packages[packageCount].packageName, STRING_LENGTH, stdin);
                    packages[packageCount].packageName[strcspn(packages[packageCount].packageName, "\n")] = '\0'; // Remove newline

                    printf("Enter destination: ");
                    fgets(packages[packageCount].destination, STRING_LENGTH, stdin);
                    packages[packageCount].destination[strcspn(packages[packageCount].destination, "\n")] = '\0'; // Remove newline

                    printf("Enter duration (days): ");
                    scanf("%d", &packages[packageCount].duration);

                    printf("Enter cost: ");
                    scanf("%f", &packages[packageCount].cost);

                    printf("Enter available seats: ");
                    scanf("%d", &packages[packageCount].availableSeats);

                    packageCount++;
                } else {
                    printf("Maximum package limit reached.\n");
                }
                break;
            case 2:
                displayPackages(packages, packageCount);
                break;
            case 3: {
                int packageNumber;
                printf("Enter package number to book: ");
                scanf("%d", &packageNumber);

                // Validate package number
                if (packageNumber > 0 && packageNumber <= packageCount) {
                    bookPackage(&packages[packageNumber - 1]);
                } else {
                    printf("Invalid package number.\n");
                }
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

