#include <stdio.h>

// Structure to represent an account
struct account
{
    int acc, age, balance, contact, pin, fd;  // Account number, age, balance, contact, PIN, and fixed deposit
    char name[100], address[200], email[100]; // Name, address, and email of the account holder
};

struct account acount[10]; // Array to store up to 10 accounts
int numacc = 0;            // Counter to keep track of the number of created accounts

// Function to verify the PIN of an account holder
int verify(int acc, int pin)
{
    // Loop through all the accounts to check if the account number and PIN match
    for (int i = 0; i < numacc; i++)
    {
        if (acount[i].acc == acc && acount[i].pin == pin)
        {
            return 1; // Return 1 if the PIN is correct
        }
    }
    return 0; // Return 0 if the account or PIN is incorrect
}

// Function to display the main menu
void menu()
{
    printf("\nMAIN MENU\n");
    printf("1. Create a new account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Fixed Deposit\n");
    printf("5. Check Balance\n");
    printf("6. Check all accounts\n");
    printf("7. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to create a new account
void acc()
{
    // Prompt the user for details to create an account
    printf("Enter the account holder name: ");
    scanf("%s", acount[numacc].name);
    printf("Enter the account number: ");
    scanf("%d", &acount[numacc].acc);
    printf("Enter your age: ");
    scanf("%d", &acount[numacc].age);

    // Check if the user is eligible to create an account (age >= 18)
    if (acount[numacc].age >= 18)
    {
        if (numacc < 100)
        { // Check if the maximum number of accounts is reached
            // Get further details for the account
            printf("Enter your contact number: ");
            scanf("%d", &acount[numacc].contact);
            printf("Enter your address: ");
            scanf(" %[^\n]s", acount[numacc].address); // Read address with spaces
            printf("Enter your email address: ");
            scanf("%s", acount[numacc].email);
            printf("Enter your PIN: ");
            scanf("%d", &acount[numacc].pin);
            printf("Enter the balance: ");
            scanf("%d", &acount[numacc].balance);
            printf("Your account has been successfully created.\n\n");
        }
        else
        {
            printf("The maximum number of accounts has been reached.\n");
        }
    }
    else
    {
        printf("You must be 18 or older to create an account.\n");
    }

    numacc++; // Increment the account counter
}

// Function to deposit money into an account
void deposit()
{
    int num, amount, pin;
    // Prompt for account number and PIN for authentication
    printf("Enter the account number: ");
    scanf("%d", &num);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    // Verify the PIN before proceeding
    if (verify(num, pin))
    {
        printf("Enter the deposit amount: ");
        scanf("%d", &amount);

        // Ensure that the deposit amount is positive
        if (amount <= 0)
        {
            printf("Deposit amount must be positive.\n");
            return;
        }

        // Find the account and update the balance
        for (int i = 0; i < numacc; i++)
        {
            if (num == acount[i].acc)
            {
                acount[i].balance += amount;
                printf("Successfully deposited %d. New balance: %d\n", amount, acount[i].balance);
                return;
            }
        }
    }
    else
    {
        printf("Invalid PIN or Account Number. Access denied.\n");
    }
}

// Function to withdraw money from an account
void withdraw()
{
    int num, amount, pin;
    // Prompt for account number and PIN for authentication
    printf("Enter the account number: ");
    scanf("%d", &num);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    // Verify the PIN before proceeding
    if (verify(num, pin))
    {
        printf("Enter the withdrawal amount: ");
        scanf("%d", &amount);

        // Ensure the withdrawal amount is positive
        if (amount <= 0)
        {
            printf("Withdrawal amount must be positive.\n");
            return;
        }

        // Find the account and check if there is enough balance
        for (int i = 0; i < numacc; i++)
        {
            if (num == acount[i].acc)
            {
                if (acount[i].balance >= amount)
                {
                    acount[i].balance -= amount;
                    printf("Successfully withdrew %d. Remaining balance: %d\n", amount, acount[i].balance);
                }
                else
                {
                    printf("Insufficient balance.\n");
                }
                return;
            }
        }
    }
    else
    {
        printf("Invalid PIN or Account Number. Access denied.\n");
    }
}

// Function to check the balance of an account
void bal()
{
    int num, pin;
    // Prompt for account number and PIN for authentication
    printf("Enter the account number: ");
    scanf("%d", &num);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    // Verify the PIN before proceeding
    if (verify(num, pin))
    {
        // Find the account and display the balance
        for (int i = 0; i < numacc; i++)
        {
            if (num == acount[i].acc)
            {
                printf("Account holder: %s\n", acount[i].name);
                printf("Balance: %d\n", acount[i].balance);
                return;
            }
        }
    }
    else
    {
        printf("Invalid PIN or Account Number. Access denied.\n");
    }
}

// Function to perform a fixed deposit transaction
void fix()
{
    int num, amount, pin;
    // Prompt for account number and PIN for authentication
    printf("Enter the account number: ");
    scanf("%d", &num);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    // Verify the PIN before proceeding
    if (verify(num, pin))
    {
        printf("Enter the fixed deposit amount: ");
        scanf("%d", &amount);

        // Ensure the fixed deposit amount is positive
        if (amount <= 0)
        {
            printf("Fixed deposit amount must be positive.\n");
            return;
        }

        // Find the account and add the fixed deposit
        for (int i = 0; i < numacc; i++)
        {
            if (num == acount[i].acc)
            {
                acount[i].fd += amount;
                printf("Fixed deposit of %d successfully added. Total FD: %d\n", amount, acount[i].fd);
                return;
            }
        }
    }
    else
    {
        printf("Invalid PIN or Account Number. Access denied.\n");
    }
}

// Function to display all the accounts and their details
void display()
{
    printf("\nAccount List:\n");
    for (int i = 0; i < numacc; i++)
    {
        printf("Name: %s\n", acount[i].name);
        printf("Account Number: %d\n", acount[i].acc);
        printf("Balance: %d\n", acount[i].balance);
        printf("Fixed Deposit: %d\n", acount[i].fd);
        printf("Contact: %d\n", acount[i].contact);
        printf("Email: %s\n", acount[i].email);
        printf("Address: %s\n\n", acount[i].address);
    }
}

// Main function to drive the program
int main()
{
    int choice;
    printf("      AXIS BANK\n");
    printf("\nWELCOME TO OUR BANK\n\n");

    do
    {
        menu(); // Display the main menu
        scanf("%d", &choice);

        // Perform the action based on the user's choice
        switch (choice)
        {
        case 1:
            acc();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            fix();
            break;
        case 5:
            bal();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting the program.\n");
            printf("Thank you for banking with us!\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7); // Loop until the user chooses to exit

    return 0;
}
