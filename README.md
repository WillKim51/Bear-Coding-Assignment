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
