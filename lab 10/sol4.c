 #include <stdio.h>
 #include <string.h>
 #define MAX_CARS 100
 #define STRING_LENGTH 50
 struct Car {
    char make[STRING_LENGTH];
    char model[STRING_LENGTH];
    int year;
    float price;
    float mileage;
 };
 void addCar(struct Car cars[], int *count);
 void displayCars(const struct Car cars[], int count);
 void searchCars(const struct Car cars[], int count);
 int main() {
    struct Car cars[MAX_CARS];
    int carCount = 0;
    int option;
    do {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add New Car\n");
        printf("2. Display Available Cars\n");
        printf("3. Search for Cars\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);
    return 0;
 }
 void addCar(struct Car cars[], int *count) {
    if (*count >= MAX_CARS) {
        printf("Cannot add more cars. The dealership is full.\n");
        return;
    }
    struct Car newCar;
    printf("Enter make: ");
    scanf("%s", newCar.make);
    printf("Enter model: ");
    scanf("%s", newCar.model);
    printf("Enter year: ");
    scanf("%d", &newCar.year);
    printf("Enter price: ");
    scanf("%f", &newCar.price);
    printf("Enter mileage: ");
    scanf("%f", &newCar.mileage);
    cars[*count] = newCar;
    (*count)++;
    printf("Car added successfully!\n");
 }
 void displayCars(const struct Car cars[], int count) {
 	int i;
    if (count == 0) {
        printf("No cars available.\n");
        return;
    }
    printf("\nAvailable Cars:\n");
    for (i = 0; i < count; i++) {
        printf("Car %d: %s %s, Year: %d, Price: $%.2f, Mileage: %.2f\n",
               i + 1, cars[i].make, cars[i].model, cars[i].year,
               cars[i].price, cars[i].mileage);
    }
 }
 void searchCars(const struct Car cars[], int count) {
 	int i;
    if (count == 0) {
        printf("No cars to search.\n");
        return;
    }
    char searchTerm[STRING_LENGTH];
    printf("Enter make or model to search: ");
    scanf("%s", searchTerm);
    int found = 0;
    printf("\nSearch Results:\n");
    for (i = 0; i < count; i++)
	 {
        if (strcmp(cars[i].make, searchTerm) == 0 || strcmp(cars[i].model, searchTerm) == 0) {
    }
            printf("Car %d: %s %s, Year: %d, Price: $%.2f, Mileage: %.2f\n",
                   i + 1, cars[i].make, cars[i].model, cars[i].year,
                   cars[i].price, cars[i].mileage);
            found = 1;
        }
    if (!found)
	 {
        printf("No cars found matching '%s'.\n", searchTerm);
    }
 }
