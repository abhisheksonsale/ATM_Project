#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    string pin;
    double balance;

public:
    ATM(string _pin, double _balance) : pin(_pin), balance(_balance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    double checkBalance() {
        return balance;
    }

    bool verifyPin(string _pin) {
        return pin == _pin;
    }
};

int main() {
    // Create ATM object with initial balance and PIN
    ATM atm("1234", 1000);

    bool continueUsing = true;

    do {
        // ATM operations
        string enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (atm.verifyPin(enteredPin)) {
            cout << "PIN verified. Choose operation:" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check Balance" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    double depositAmount;
                    cout << "Enter amount to deposit: $";
                    cin >> depositAmount;
                    atm.deposit(depositAmount);
                    break;
                case 2:
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: $";
                    cin >> withdrawAmount;
                    atm.withdraw(withdrawAmount);
                    break;
                case 3:
                    cout << "Current balance: $" << atm.checkBalance() << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } else {
            cout << "Invalid PIN. Access denied." << endl;
        }

        char choice;
        cout << "Do you want to perform another transaction? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            continueUsing = false;
        }
    } while (continueUsing);

    return 0;
}
