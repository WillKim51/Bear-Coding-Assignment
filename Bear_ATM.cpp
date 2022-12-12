// Implement a simple ATM controller.
// Insert Card -> PIN number -> Select Account -> See Balance/Deposit/Withdraw.
// For simplification, only 1 dollar bills.

#include <iostream>
#include <map>

using namespace std;

void ShowFirstMenu();
int NewAccount();
int SelectAccount();
void ShowAccountMenu();

class Account{
    private: 
        int accountNumber;
        int pin;
        int cBalance = 0;
        int sBalance = 0;
    public:
        Account(int accountNumber, int pin){
            this->accountNumber = accountNumber;
            this->pin = pin;
        }
        bool CheckPin(int pinInput);
        void ShowBalance();
        void Deposit();
        void Withdraw();
};

map<int, Account> accountMap;

int main(){
    int option;
    bool continueFirstMenu = true;
    bool continueAccountMenu = true;
    int id; 

    while(continueFirstMenu){
        cout << endl;
        ShowFirstMenu();
        cout << "Option: ";
        cin >> option;

        switch (option){
            case 1:
                id = NewAccount();
                continueAccountMenu = true;
                break;
            case 2: 
                id = SelectAccount();
                continueAccountMenu = id == -1 ? false : true;
                break;
            case 3:
                continueFirstMenu = false;
                continueAccountMenu = false;
                cout << "Thank you for using Bear bank!" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                continueAccountMenu = false;
        }

        Account& tempAccount = accountMap.find(id)->second;

        while(continueAccountMenu){
            ShowAccountMenu();
            cout << "Option: ";
            cin >> option;
            switch(option){
                case 1:
                    tempAccount.ShowBalance();
                    break;
                case 2:
                    tempAccount.Deposit();
                    break;
                case 3:
                    tempAccount.Withdraw();
                    break;
                case 4:
                    continueAccountMenu = false;
                    break;
                case 5:
                    continueAccountMenu = false;
                    continueFirstMenu = false;
                    cout << "Thank you for using Bear bank!" << endl;
                    break;
                default:
                    cout << "Invalid option" << endl;
            }
        }
    }
    return 0;
}

void ShowFirstMenu(){
    cout << endl;
    cout << "-----Welcome to Bear Bank-----" << endl;
    cout << "1: Create a new account" << endl;
    cout << "2: Insert card (type in your account number)" << endl;
    cout << "3: Exit from ATM" << endl;
}

int NewAccount(){
    int id;
    int pin;
    cout << endl;
    cout << "Please create a new account" << endl;
    cout << "Create an account number: ";
    cin >> id;
    cout << "Create a password: ";
    cin >> pin;
    accountMap.insert(pair<int, Account>(id, Account(id, pin)));
    return id;
}

int SelectAccount(){
    int id;
    int pin;
    cout << endl;
    cout << "Enter your account number: ";
    cin >> id;
    if(accountMap.find(id) == accountMap.end()){
        cout << "The account does not exist" << endl;
        return -1;
    }
    cout << "Enter your pin: ";
    cin >> pin;

    Account& tempAccount = accountMap.find(id)->second;
    bool isPinCorrect = tempAccount.CheckPin(pin);

    if (!isPinCorrect){
        cout << "Invalid pin" << endl;
        return -1; 
    }
    else{
        return id;
    }
}

void ShowAccountMenu(){
    cout << endl;
    cout << "1: Show balance" << endl;
    cout << "2: Deposit" << endl;
    cout << "3: Withdraw" << endl;
    cout << "4: New user" << endl;
    cout << "5: Exit from ATM" << endl;
}

void Account::ShowBalance(){
    cout << endl;
    cout << "Checking account balance: " << cBalance << endl;
    cout << "Savings account balance: " << sBalance << endl;
}

bool Account::CheckPin(int pinInput){
    return pinInput == pin? true : false;
}

void Account::Deposit(){
    int option;
    int amount;
    cout << endl;
    cout << "Choose your account: " << endl;
    cout << "1: Checking" << endl;
    cout << "2: Savings" << endl;
    cout << "Option: ";
    cin >> option;
    switch(option){
        case 1:
            cout << endl;
            cout << "Enter deposit amount: ";
            cin >> amount;
            cBalance += amount;
            break;
        case 2:
            cout << endl;
            cout << "Enter deposit amount: ";
            cin >> amount;
            sBalance += amount;
            break;
        default:
            cout << "Invalid option" << endl;        
    }
}

void Account::Withdraw(){
    int option;
    int amount;
    cout << endl;
    cout << "Choose your account: " << endl;
    cout << "1: Checking" << endl;
    cout << "2: Savings" << endl;
    cout << "Option: ";
    cin >> option;
    switch(option){
        case 1:
            cout << endl;
            cout << "Enter withdraw amount: ";
            cin >> amount;
            if(amount > cBalance){
                cout << "Insufficient checking balance" << endl;
            }
            else{
                cBalance -= amount;
            }
            break;
        case 2:
            cout << endl;
            cout << "Enter withdraw amount: ";
            cin >> amount;
            if(amount > sBalance){
                cout << "Insufficient savings balance" << endl;
            }
            else{
                sBalance -= amount;
            }
            break;
        default:
            cout << "Invalid option" << endl;        
    }
}