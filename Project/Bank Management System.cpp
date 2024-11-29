#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_FILE "account.dat"
#define ADMIN_PASSWORD "FawadIsAdmin"

typedef struct {
    char name[50];
    int acc_no;
    float balance;
    char password[20];
} Account;

void create_account();
void login_account();
void admin_access_to_the_list_of_accounts();
void search_for_accounts();
void modify_account_details();
void basic_faqs();
//void live_chat();
void deposit_money(int acc_no);
void withdraw_money(int acc_no);
void check_balance(int acc_no);
void transfer_money(int acc_no);
void change_password(int acc_no);
void low_balance_or_unusual_activity();
void close_account(int acc_no);
void delete_account(int acc_no);
void admin_modify_account_details(int acc_no);

int main() {
    while (1) {
    	
        int choice;
        printf("\n\n*** Welcome to FAST Bank ***\n\n");
        printf("1. Create Account\n");
        printf("2. Login Account\n");
        printf("3. Admin Access to the List of Accounts\n");
        printf("4. Basic FAQs\n");
//        printf("5. Live Chat\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: 
			create_account(); 
			break;
            
            case 2: 
				login_account(); 
			break;
            
            case 3: 
				admin_access_to_the_list_of_accounts(); 
			break;
            
            case 4: 
				basic_faqs(); 
			break;
            
//            case 5: 
//				live_chat(); 
//			break;
            
            case 5: 
                printf("Thank you for using FAST Bank. Goodbye!\n"); 
                exit(0);
                
            default: 
                printf("Invalid choice. Try again.\n"); 
                break;
        }
    }
}

void create_account() {
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Enter Your Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    printf("Enter Account Number: ");
    if (scanf("%d", &acc.acc_no) != 1) {
        printf("Invalid input. Please enter a valid account number.\n");
        fclose(file);
        while (getchar() != '\n');
        return;
    }

    printf("Set a Password: ");
    scanf("%s", acc.password);

    acc.balance = 0.0;

    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);
    printf("Account created successfully!\n");
}

void login_account() {
    int acc_no;
    char password[20];
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter Password: ");
    scanf("%s", password);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no && strcmp(acc.password, password) == 0) {
            fclose(file);
            printf("Login successful. Welcome, %s!\n", acc.name);
            int login_choice;
            while (1) {
                printf("\n\n*** Account Menu ***\n\n");
                printf("1. Deposit Money\n");
                printf("2. Withdraw Money\n");
                printf("3. Check Balance\n");
                printf("4. Transfer Money\n");
                printf("5. Change Password\n");
                printf("6. Low Balance or Unusual Activity\n");
                printf("7. Close Account (Back to Main Menu)\n");
                printf("8. Delete Account\n");
                printf("Enter Your Choice: ");

                if (scanf("%d", &login_choice) != 1) {
                    printf("Invalid input! Please enter a number between 1 and 8.\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');

                switch (login_choice) {
                    case 1: 
					deposit_money(acc_no); 
					break;
                    
                    case 2: 
					withdraw_money(acc_no); 
					break;
                    
                    case 3: 
					check_balance(acc_no); 
					break;
                    
                    case 4: 
					transfer_money(acc_no); 
					break;
                    
                    case 5: 
					change_password(acc_no); 
					break;
                    
                    case 6: 
					low_balance_or_unusual_activity(); 
					break;
                    
                    case 7: 
					close_account(acc_no); 
					return;
                    
                    case 8: 
					delete_account(acc_no); 
					return;
                    
                    default: 
					printf("Invalid choice. Try again.\n"); 
					break;
                }
            }
        }
    }

    fclose(file);
    printf("Invalid account number or password.\n");
}

void admin_access_to_the_list_of_accounts() {
    char password[20];
    printf("Enter Admin Password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASSWORD) != 0) {
        printf("Invalid password! Access denied.\n");
        return;
    }

    int admin_choice;
    while (1) {
        printf("\n\n*** Admin Menu ***\n\n");
        printf("1. Search for Accounts\n");
        printf("2. Modify Account Details\n");
        printf("3. Back to Main Menu\n");
        printf("Enter Your Choice: ");

        if (scanf("%d", &admin_choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (admin_choice) {
            case 1: search_for_accounts(); break;
            case 2: modify_account_details(); break;
            case 3: return;
            default: printf("Invalid choice. Try again.\n"); break;
        }
    }
}

void search_for_accounts() {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int acc_no;
    printf("Enter Account Number to Search: ");
    scanf("%d", &acc_no);

    Account acc;
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            printf("Account Found: Name: %s, Account No: %d, Balance: %.2f\n", acc.name, acc.acc_no, acc.balance);
            fclose(file);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(file);
}

void modify_account_details() {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int acc_no;
    Account acc;

    printf("Enter Account Number to Modify: ");
    scanf("%d", &acc_no);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            int modify_choice;
            printf("\n\n*** Modify Account Menu ***\n\n");
            printf("1. Change Name\n");
            printf("2. Change Password\n");
            printf("3. Delete Account\n");
            printf("Enter Your Choice: ");

            scanf("%d", &modify_choice);
            switch (modify_choice) {
                case 1:
                    printf("Enter New Name: ");
                    getchar();
                    fgets(acc.name, sizeof(acc.name), stdin);
                    acc.name[strcspn(acc.name, "\n")] = '\0';
                    break;
                case 2:
                    printf("Enter New Password: ");
                    scanf("%s", acc.password);
                    break;
                case 3:
                    fclose(file);
                    delete_account(acc.acc_no);
                    return;
                default:
                    printf("Invalid choice.\n");
                    fclose(file);
                    return;
            }

            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            fclose(file);
            printf("Account details updated successfully.\n");
            return;
        }
    }

    fclose(file);
    printf("Account not found.\n");
}

void basic_faqs() {
    printf("\nFAQs\n");
    printf("Q: What are Your banking Hours?\n");
    printf("A: Our Bank is Open 7 Days a Week 24 Hours a day.\n\n");
    printf("Q: How do I open an Account in FAST Bank?\n");
    printf("A: Choose Option 1 in Menu, Enter Your Name, Account Number, and Password.\n\n");
    printf("Q: Does FAST Bank offer any loans?\n");
    printf("A: No, Not for Now\n\n");
}

//void live_chat() {
//    char user_input[100];
//    int is_running = 1;
//
//    printf("\nWelcome to the FAST Bank Live AI Chatbot!\n");
//
//    while (is_running) {
//        printf("How can I help you today?\n");
//
//        if (fgets(user_input, 100, stdin) == NULL) {
//            printf("Error reading input. Please try again.\n");
//            continue;
//        }
//
//        if (strstr(user_input, "balance") != NULL) {
//            printf("I am unauthorized to know this Information.\n");
//        } else if (strstr(user_input, "transfer") != NULL) {
//            printf("To transfer funds, please Select the Transfer Money option.\n");
//        } else if (strstr(user_input, "exit") != NULL || strstr(user_input, "bye") != NULL) {
//            printf("Goodbye! Have a Nice Day.\n");
//            is_running = 0;
//        } else {
//            printf("Sorry, I didn't understand that. Can you please rephrase?\n");
//        }
//    }
//}

void deposit_money(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc;
    float amount;
    int found = 0;

    printf("Enter Amount to Deposit (in Rs.): ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Deposit failed.\n");
        fclose(file);
        return;
    }

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            acc.balance += amount;
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            printf("Deposit successful. New Balance: Rs.%.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Account not found.\n");
    }
}

void withdraw_money(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc;
    float amount;
    int found = 0;

    printf("Enter Amount to Withdraw (in Rs.): ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal failed.\n");
        fclose(file);
        return;
    }

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            if (acc.balance < amount) {
                printf("Insufficient balance. Withdrawal failed.\n");
                fclose(file);
                return;
            }
            acc.balance -= amount;
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            printf("Withdrawal successful. New Balance: Rs.%.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Account not found.\n");
    }
}

void check_balance(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            printf("Your Current Balance: Rs.%.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Account not found.\n");
    }
}

void transfer_money(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc_from, acc_to;
    int to_acc_no, found_from = 0, found_to = 0;
    float amount;

    printf("Enter Account Number to Transfer To: ");
    scanf("%d", &to_acc_no);
    printf("Enter Amount to Transfer: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Transfer failed.\n");
        fclose(file);
        return;
    }

    while (fread(&acc_from, sizeof(Account), 1, file)) {
        if (acc_from.acc_no == acc_no) {
            found_from = 1;
            if (acc_from.balance < amount) {
                printf("Insufficient balance. Transfer failed.\n");
                fclose(file);
                return;
            }
            break;
        }
    }

    rewind(file);

    while (fread(&acc_to, sizeof(Account), 1, file)) {
        if (acc_to.acc_no == to_acc_no) {
            found_to = 1;
            break;
        }
    }

    if (found_from && found_to) {
        acc_from.balance -= amount;
        acc_to.balance += amount;

        fseek(file, -sizeof(Account) * 2, SEEK_CUR);
        fwrite(&acc_from, sizeof(Account), 1, file);

        fwrite(&acc_to, sizeof(Account), 1, file);

        printf("Transfer successful. New Balance: %.2f\n", acc_from.balance);
    } else {
        printf("Account(s) not found. Transfer failed.\n");
    }

    fclose(file);
}

void change_password(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc;
    char new_password[20];
    int found = 0;

    printf("Enter New Password: ");
    scanf("%s", new_password);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no == acc_no) {
            strcpy(acc.password, new_password);
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            printf("Password changed successfully.\n");
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Account not found.\n");
    }
}

void low_balance_or_unusual_activity() {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Account acc;
    int found =0; //flag to  track if any account is found

    printf("Accounts with Balance Below Rs.100:\n");
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.balance < 100.0) {
            printf("Account No: %d, Name: %s, Balance: Rs.%.2f\n", acc.acc_no, acc.name, acc.balance);
            found = 1;
        }
    }
    
    if(!found){
    	printf("NO ccounts found with balance below Rs.100.\n");
	}

    fclose(file);
}

void close_account(int acc_no) {
    printf("Closing account and returning to main menu.\n");
}

void delete_account(int acc_no) {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!file || !temp) {
        perror("Error opening file");
        return;
    }

    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.acc_no != acc_no) {
            fwrite(&acc, sizeof(Account), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(ACCOUNT_FILE);
    rename("temp.dat", ACCOUNT_FILE);

    if (found) {
        printf("Account deleted successfully.\n");
    } else {
        printf("Account not found.\n");
    }
}

void admin_modify_account_details(int acc_no) {
    modify_account_details();
}
