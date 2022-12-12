# Bear-Coding-Assignment

## Overview
This is an assignment for Bear Robotics coding test. 

## Objective
Write code for a simple ATM, a controller should be implemented and tested. 

At least the following flow should be implemented:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills used. 

## Installation
To clone this github repository, run the following command on your desired directory.
```bash
git clone https://github.com/WillKim51/Bear-Coding-Assignment
```

Change your directory to the newly created Bear-Coding-Assignment folder.
```bash
cd Bear-Coding-Assignment
```
Build the downloaded C++ file by running the following command. 
```bash
g++ -o ./Bear_ATM ./Bear_ATM.cpp
```

Lastly, run the executable file by running the following command.
```bash
./Bear_ATM
```

Then, you should see the initial menu pop up on your terminal screen. 

## Methods
1. Users can either choose to create a new account or insert card (entering account number)
2. User must type in a new pin when creating a new account, or a correct pin when inserting card. 
3. Once user account is selected, users can choose between checking account and savings account. 
4. Once the account is selected, users can choose to show balance, deposit, or withdraw.
5. Program continues until user selects exit option. 

## Test Example (brief overview)
Below shows an example of a test scenario. 
Detailed explanation can be found in the next section.

```text
-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 1

Please create a new account
Create an account number: 1234567
Create a password: 0000

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 2

Choose your account: 
1: Checking
2: Savings
Option: 1

Enter deposit amount: 50

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 3

Choose your account: 
1: Checking
2: Savings
Option: 1

Enter withdraw amount: 60
Insufficient checking balance

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 1

Checking account balance: 50
Savings account balance: 0

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 4


-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 1

Please create a new account
Create an account number: 7654321
Create a password: 1111

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 2

Choose your account: 
1: Checking
2: Savings
Option: 2

Enter deposit amount: 100

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 4


-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 2

Enter your account number: 123456 
The account does not exist


-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 2

Enter your account number: 1234567
Enter your pin: 0000

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 3

Choose your account: 
1: Checking
2: Savings
Option: 1

Enter withdraw amount: 20

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 1

Checking account balance: 30
Savings account balance: 0

1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 5
Thank you for using Bear bank!
```

## Test Example (with detailed explanation)

Initial welcome message.
User selects option 1, to create a new account.
```text
-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 1
```

User creates a new account number (1234567) and a password (0000)
```text
Please create a new account
Create an account number: 1234567
Create a password: 0000
```

Then, the program shows account menu. 
User selects option 2, to deposit money.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 2
```

Then, the program asks which account, user selects checking account. 
```text
Choose your account: 
1: Checking
2: Savings
Option: 1
```

Then, the program asks the amount to be deposited, user enters 50.
```text
Enter deposit amount: 50
```

After the deposit is made, the program goes back to the account menu. 
User selects option 3, to withdraw money.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 3
```

User selects checking account where the deposit was just made. 
```text
Choose your account: 
1: Checking
2: Savings
Option: 1
```

User enters withdrawal amount of 60, which is more than the balance 50. 
The program warns that the balance is insufficient and withdrawal is cancelled.
```text
Enter withdraw amount: 60
Insufficient checking balance
```

Then, going back to the account menu, user selects option 1, to show balance.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 1
```

The program prints out the balance of both checking and savings accounts.
```text
Checking account balance: 50
Savings account balance: 0
```

User is done with his business and next person takes the ATM.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 4
```

The second user creates a new account, same as before, entering new account number and pin.
```text
-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 1

Please create a new account
Create an account number: 7654321
Create a password: 1111
```

The second user deposits 100 in the savings account. 
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 2

Choose your account: 
1: Checking
2: Savings
Option: 2

Enter deposit amount: 100
```

The second user leaves the ATM, but the first user comes back because he/she needs some cash withdrawal.
This time, because the first user already made an account, he/she inserts the card.
```text
-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 2
```

The first user makes a mistake while typing in the account number (or the card reader made an error)
```text
Enter your account number: 123456 
The account does not exist
```

This time, he/she makes no mistake (or the card reader functions as intended)
```text
-----Welcome to Bear Bank-----
1: Create a new account
2: Insert card (type in your account number)
3: Exit from ATM
Option: 2

Enter your account number: 1234567
Enter your pin: 0000
```

The first user selects option 3 to withdraw cash, and this time he/she makes sure it is smaller than the balance.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 3

Choose your account: 
1: Checking
2: Savings
Option: 1

Enter withdraw amount: 20
```

The first user selects option 1 to check the remaining balance.
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 1

Checking account balance: 30
Savings account balance: 0
```

No more customers for the day, exiting the program. 
```text
1: Show balance
2: Deposit
3: Withdraw
4: New user
5: Exit from ATM
Option: 5
Thank you for using Bear bank!
```





