# Simple Banking System in C

This is a simple command-line banking system implemented in C. It allows you to create accounts, deposit and withdraw funds, display account information, and save account data to a file.

## How to Compile and Run

1. Compile the code using a C compiler (e.g., gcc):
gcc -o banking main.c
2. Run the program:
./banking

## Usage Instructions

1. Choose from the following options in the menu:
- Create Account: Create a new bank account.
- Deposit: Deposit funds into an existing account.
- Withdraw: Withdraw funds from an existing account.
- Display Accounts: View account details.
- Save Accounts: Save account data to a file.
- Exit: Exit the banking system.

2. Follow the on-screen prompts to perform your desired actions.

## Code Explanation

- The code uses a struct to represent bank accounts and functions to perform various banking operations.
- Account data is loaded from and saved to a file (`accounts.txt`) to persist data between program runs.

Feel free to explore the code and experiment with the banking system. It's designed for educational purposes and can serve as a starting point for more advanced projects.
