#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct player{
    char name[20];
    char team[20];
};

struct bowl{
    char type[20];
    char arm[20];
    struct player ply;
};

struct bat{
    char type[20];
    char handed[20];
    struct bowl ply2;
};


// Function to create a new record
void createrecord() {
    FILE *fp;
    struct bat player;

    fp = fopen("batsmen.txt", "a"); // Open the file in write mode to create/overwrite
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    // Prompt the user to enter the batsman's details
    printf("Enter batsman type (e.g., 'Right-handed', 'Left-handed'): ");
    scanf("%s", player.type);
    
    printf("Enter handedness (e.g., 'Right', 'Left'): ");
    scanf("%s", player.handed);
    
    // Now prompt for the bowler's information
    printf("Enter bowler type (e.g., 'Fast', 'Spin'): ");
    scanf("%s", player.ply2.type);
    
    printf("Enter bowler arm (e.g., 'Right-arm', 'Left-arm'): ");
    scanf("%s", player.ply2.arm);
    
    // For player name and team under the bowler's struct
    printf("Enter player's name (bowler): ");
    scanf("%s", player.ply2.ply.name);
    
    printf("Enter player's team: ");
    scanf("%s", player.ply2.ply.team);

    // Write the data to the file
    fprintf(fp, "Batsman Type: %s\n", player.type);
    fprintf(fp, "Handedness: %s\n", player.handed);
    fprintf(fp, "Bowler Type: %s\n", player.ply2.type);
    fprintf(fp, "Bowler Arm: %s\n", player.ply2.arm);
    fprintf(fp, "Bowler Name: %s\n", player.ply2.ply.name);
    fprintf(fp, "Bowler Team: %s\n", player.ply2.ply.team);

    printf("Record created successfully!\n");

    fclose(fp);
}

// Function to read records from a file
void readrecord() {
    FILE *fp;
    struct bat player;

    // Open the file in read mode
    fp = fopen("batsmen.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened for reading.\n");
        return;
    }

    // Keep reading the data until the end of the file
    while (fscanf(fp, "Batsman Type: %s\n", player.type) == 1) {
        fscanf(fp, "Handedness: %s\n", player.handed);
        fscanf(fp, "Bowler Type: %s\n", player.ply2.type);
        fscanf(fp, "Bowler Arm: %s\n", player.ply2.arm);
        fscanf(fp, "Bowler Name: %s\n", player.ply2.ply.name);
        fscanf(fp, "Bowler Team: %s\n", player.ply2.ply.team);

        // Print the data read from the file
        printf("Batsman Type: %s\n", player.type);
        printf("Handedness: %s\n", player.handed);
        printf("Bowler Type: %s\n", player.ply2.type);
        printf("Bowler Arm: %s\n", player.ply2.arm);
        printf("Bowler Name: %s\n", player.ply2.ply.name);
        printf("Bowler Team: %s\n", player.ply2.ply.team);
        printf("\n");
    }

    // Close the file after reading
    fclose(fp);
}

// Function to update a record in the file
void updaterecord() {
    FILE *fp, *temp;
    struct bat player;
    char updatedHanded[20];
    char targetName[20];
    int found = 0;

    // Open the original file in read mode
    fp = fopen("batsmen.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened for reading.\n");
        return;
    }

    // Create a temporary file to write the updated contents
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Temporary file cannot be created.\n");
        fclose(fp);
        return;
    }

    // Get the player's name whose record you want to update
    printf("Enter the name of the bowler whose record you want to update: ");
    scanf("%s", targetName);

    // Read the file and copy to temp file, modifying the record if necessary
    while (fscanf(fp, "Batsman Type: %s\n", player.type) == 1) {
        fscanf(fp, "Handedness: %s\n", player.handed);
        fscanf(fp, "Bowler Type: %s\n", player.ply2.type);
        fscanf(fp, "Bowler Arm: %s\n", player.ply2.arm);
        fscanf(fp, "Bowler Name: %s\n", player.ply2.ply.name);
        fscanf(fp, "Bowler Team: %s\n", player.ply2.ply.team);

        // Check if the current bowler's name matches the target name
        if (strcmp(player.ply2.ply.name, targetName) == 0) {
            found = 1;

            // Update the handedness
            printf("Enter new handedness for %s: ", targetName);
            scanf("%s", updatedHanded);

            // Update the record in memory
            strcpy(player.handed, updatedHanded);
        }

        // Write the data (modified or not) to the temporary file
        fprintf(temp, "Batsman Type: %s\n", player.type);
        fprintf(temp, "Handedness: %s\n", player.handed);
        fprintf(temp, "Bowler Type: %s\n", player.ply2.type);
        fprintf(temp, "Bowler Arm: %s\n", player.ply2.arm);
        fprintf(temp, "Bowler Name: %s\n", player.ply2.ply.name);
        fprintf(temp, "Bowler Team: %s\n", player.ply2.ply.team);
    }

    if (found) {
        printf("Record updated successfully!\n");
    } else {
        printf("Bowler not found in the records.\n");
    }

    // Close both files
    fclose(fp);
    fclose(temp);

    // Remove the original file and rename the temporary file to the original file's name
    remove("batsmen.txt");
    rename("temp.txt", "batsmen.txt");
}


// Function to delete a record from the file
void deleterecord() {
    FILE *fp, *temp;
    struct bat player;
    char targetName[20];
    int found = 0;

    // Open the original file in read mode
    fp = fopen("batsmen.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened for reading.\n");
        return;
    }

    // Create a temporary file to write the new contents
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Temporary file cannot be created.\n");
        fclose(fp);
        return;
    }

    // Get the player's name whose record you want to delete
    printf("Enter the name of the bowler whose record you want to delete: ");
    scanf("%s", targetName);

    // Read the file and copy to temp file, skipping the record to delete
    while (fscanf(fp, "Batsman Type: %s\n", player.type) == 1) {
        fscanf(fp, "Handedness: %s\n", player.handed);
        fscanf(fp, "Bowler Type: %s\n", player.ply2.type);
        fscanf(fp, "Bowler Arm: %s\n", player.ply2.arm);
        fscanf(fp, "Bowler Name: %s\n", player.ply2.ply.name);
        fscanf(fp, "Bowler Team: %s\n", player.ply2.ply.team);

        // Check if the current bowler's name matches the target name
        if (strcmp(player.ply2.ply.name, targetName) != 0) {
            // If the name doesn't match, write the record to the temporary file
            fprintf(temp, "Batsman Type: %s\n", player.type);
            fprintf(temp, "Handedness: %s\n", player.handed);
            fprintf(temp, "Bowler Type: %s\n", player.ply2.type);
            fprintf(temp, "Bowler Arm: %s\n", player.ply2.arm);
            fprintf(temp, "Bowler Name: %s\n", player.ply2.ply.name);
            fprintf(temp, "Bowler Team: %s\n", player.ply2.ply.team);
        } else {
            found = 1;
        }
    }

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Bowler not found in the records.\n");
    }

    // Close both files
    fclose(fp);
    fclose(temp);

    // Remove the original file and rename the temporary file to the original file's name
    remove("batsmen.txt");
    rename("temp.txt", "batsmen.txt");
}

int main()
{
    int choice;
    while(1)
    {
        printf("1. Create record\n");
        printf("2. Read record\n");
        printf("3. Update record\n");
        printf("4. Delete record\n");
        printf("5. Exit record\n");
        printf("Enter your choice:  ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            createrecord();
            break;
            case 2:
            readrecord();
            break;
            case 3:
            updaterecord();
            break;
            case 4:
            deleterecord();
            break;
            case 5:
            printf("Exiting program...\n");
            return 0;
            default:
            printf("invalid choice.\n");
        }
    }
}

