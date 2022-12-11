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
void ShowBalance(int id);
void Deposit(int id);
void Withdraw(int id);

struct Account{
    int pin; // password
    int cBalance; // checking balance
    int sBalance; // savings balance
};
map<int, Account> accountMap; // map of all the accounts created. 

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
        }
        
        while(continueAccountMenu){
            ShowAccountMenu();
            cout << "Option: ";
            cin >> option;
            switch(option){
                case 1:
                    ShowBalance(id);
                    break;
                case 2:
                    Deposit(id);
                    break;
                case 3:
                    Withdraw(id);
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
    int accID;
    int pin;
    struct Account temp;
    cout << endl;
    cout << "Please create a new account" << endl;
    cout << "Create an account number: ";
    cin >> accID;
    cout << "Create a password: ";
    cin >> pin;
    temp.pin = pin;
    temp.cBalance = 0;
    temp.sBalance = 0;
    accountMap[accID] = temp;
    return accID;
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
    if (accountMap[id].pin != pin){
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

void ShowBalance(int id){
    cout << endl;
    cout << "Checking account balance: " << accountMap[id].cBalance << endl;
    cout << "Savings account balance: " << accountMap[id].sBalance << endl;
}

void Deposit(int id){
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
            accountMap[id].cBalance += amount;
            break;
        case 2:
            cout << endl;
            cout << "Enter deposit amount: ";
            cin >> amount;
            accountMap[id].sBalance += amount;
            break;
        default:
            cout << "Invalid option" << endl;        
    }
}

void Withdraw(int id){
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
            if(amount > accountMap[id].cBalance){
                cout << "Insufficient checking balance" << endl;
            }
            else{
                accountMap[id].cBalance -= amount;
            }
            break;
        case 2:
            cout << endl;
            cout << "Enter deposit amount: ";
            cin >> amount;
            if(amount > accountMap[id].sBalance){
                cout << "Insufficient savings balance" << endl;
            }
            else{
                accountMap[id].sBalance -= amount;
            }
            break;
        default:
            cout << "Invalid option" << endl;        
    }
}