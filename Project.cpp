#include <iostream>
using namespace std;

int accountNo[10];
int balance[10];
int total = 0;

void createAccount() {
    accountNo[total] = total + 1;
    cout << "Enter initial balance: ";
    cin >> balance[total];
    cout << "Account created. Account Number: " << accountNo[total] << endl;
    total++;
}

void deposit() {
    int acc, amount;
    cout << "Enter account number: ";
    cin >> acc;

    for (int i = 0; i < total; i++) {
        if (accountNo[i] == acc) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            balance[i] += amount;
            cout << "Amount deposited.\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdraw() {
    int acc, amount;
    cout << "Enter account number: ";
    cin >> acc;

    for (int i = 0; i < total; i++) {
        if (accountNo[i] == acc) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            if (amount > balance[i])
                cout << "Insufficient balance!\n";
            else {
                balance[i] -= amount;
                cout << "Withdrawal successful.\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

void checkBalance() {
    int acc;
    cout << "Enter account number: ";
    cin >> acc;

    for (int i = 0; i < total; i++) {
        if (accountNo[i] == acc) {
            cout << "Balance: " << balance[i] << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- BANK MANAGEMENT SYSTEM ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) createAccount();
        else if (choice == 2) deposit();
        else if (choice == 3) withdraw();
        else if (choice == 4) checkBalance();
        else if (choice == 5) break;
        else cout << "Invalid choice!\n";
    }

    return 0;
}
