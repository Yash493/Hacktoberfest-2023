
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for customer accounts
struct Account {
    int accountNumber;
    char name[50];
    double balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *accountCount) {
    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);

    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    printf("Account created successfully!\n");
}

// Function to deposit funds into an account
void deposit(struct Account accounts[], int accountCount) {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter deposit amount: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. Updated balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to withdraw funds from an account
void withdraw(struct Account accounts[], int accountCount) {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter withdrawal amount: ");
            scanf("%lf", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. Updated balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to display account information
void displayAccounts(const struct Account accounts[], int accountCount) {
    printf("Account Number\tAccount Holder\tBalance\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%d\t\t%s\t\t%.2lf\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

// Function to save account data to a file
void saveAccountsToFile(const struct Account accounts[], int accountCount) {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%d %s %.2lf\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }

    fclose(file);
}

// Function to load account data from a file
int loadAccountsFromFile(struct Account accounts[], int *accountCount) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 0;  // Return 0 to indicate failure
    }

    while (fscanf(file, "%d %s %lf", &accounts[*accountCount].accountNumber, accounts[*accountCount].name,
                  &accounts[*accountCount].balance) == 3) {
        (*accountCount)++;
    }

    fclose(file);
    return 1;  // Return 1 to indicate success
}

int main() {
    struct Account accounts[100];  // Maximum 100 accounts
    int accountCount = 0;
    int choice;

    // Load account data from file at program start
    if (!loadAccountsFromFile(accounts, &accountCount)) {
        printf("No existing account data found.\n");
    }

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Accounts\n");
        printf("5. Save Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                deposit(accounts, accountCount);
                break;
            case 3:
                withdraw(accounts, accountCount);
                break;
            case 4:
                displayAccounts(accounts, accountCount);
                break;
            case 5:
                saveAccountsToFile(accounts, accountCount);
                break;
            case 6:
                printf("Exiting the Banking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
