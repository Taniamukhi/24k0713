 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #define MAX_MOVIES 100
typedef struct {
    char title[100];
    char genre[50];
    char director[50];
    int releaseYear;
    float rating;
 } Movie;
 Movie movies[MAX_MOVIES];
 int movieCount=0;
 void toLowerCase(char *str) {
 	int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
 }
 void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }
    printf("\n--- Add a New Movie ---\n");
    printf("Enter movie title: ");
    getchar(); 
    fgets(movies[movieCount].title, sizeof(movies[movieCount].title), stdin);
    movies[movieCount].title[strcspn(movies[movieCount].title, "\n")] = '\0';
    printf("Enter genre: ");
    fgets(movies[movieCount].genre, sizeof(movies[movieCount].genre), stdin);
    movies[movieCount].genre[strcspn(movies[movieCount].genre, "\n")] = '\0';
    printf("Enter director: ");
    fgets(movies[movieCount].director, sizeof(movies[movieCount].director), stdin);
    movies[movieCount].director[strcspn(movies[movieCount].director, "\n")] = '\0';
    printf("Enter release year: ");
    scanf("%d", &movies[movieCount].releaseYear);
    if (movies[movieCount].releaseYear < 1888 || movies[movieCount].releaseYear > 2100) {
        printf("Invalid release year. Please enter a year between 1888 and 2100.\n");
        return;
    }
    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[movieCount].rating);
    if (movies[movieCount].rating < 0 || movies[movieCount].rating > 10) {
        printf("Invalid rating. Please enter a value between 0 and 10.\n");
        return;
    }
    movieCount++;
    printf("Movie added successfully!\n");
 }
 void searchByGenre() {
 	int i;
    char searchGenre[50];
    int found=0;
    printf("\n--- Search Movies by Genre ---\n");
    printf("Enter genre to search: ");
    getchar();
    fgets(searchGenre, sizeof(searchGenre), stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';
    char lowerSearchGenre[50];
    strcpy(lowerSearchGenre, searchGenre);
    toLowerCase(lowerSearchGenre);
    for (i = 0; i < movieCount; i++) {
        char lowerGenre[50];
        strcpy(lowerGenre, movies[i].genre);
        toLowerCase(lowerGenre);
        if (strcmp(lowerGenre, lowerSearchGenre) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in the genre '%s'.\n", searchGenre);
    }
 }
 void displayMovies() {
 	int i;
    if (movieCount == 0) {
        printf("\nNo movies available.\n");
        return;
    }
    printf("\n--- All Movies ---\n");
    for (i = 0; i < movieCount; i++) {
        printf("\nTitle: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
    }
 }
 int main() 
 {
    int choice;
    do {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                searchByGenre();
                break;
            case 3:
                displayMovies();
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
