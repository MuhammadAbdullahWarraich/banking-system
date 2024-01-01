#include "bank.h"
int main(){
  cout << "hello cool world\n";
  Bank mybank;
  while (true){
    int choice;
    do{
      cout << "enter 1 for creating a new account,\n enter 2 for performing a transaction using an existing account,\n and press 3 for removing an existing account,\n enter 4 to exit program\n\n";
      cin >> choice;
    }while (choice!=1 && choice!=2 && choice!=3 && choice!=4);
    if (choice==1){
      string account_title;
      int account_balance;
      cout << "Enter Account Title: ";
      cin.ignore();
      getline(cin, account_title);
      cout << "Enter Initial Account Balance: ";
      cin >> account_balance;
      mybank.addNewAccount(account_title, account_balance);
    }
    else if (choice==2){
      if (mybank.isEmpty()){
        cout << "No accounts available!\n\n";
      }
      else{
        do{
          cout << "enter 1 for performing debit transactions,\n enter 2 for performing credit transactions,\n enter 3 for merging two accounts,\n and enter 4 for money transfer:\n\n";
          cin >> choice;
        }while (choice!=1 && choice!=2 && choice!=3 && choice!=4);
        if (choice==1 || choice==2){
          int accNo;
          cout << "enter account number for transaction: ";
          cin >> accNo;
          string transaction_type;
          if (choice==1)  transaction_type="debit";
          else  transaction_type="credit";
          int amount;
          cout << "enter amount for transaction: ";
          cin >> amount;
          mybank.performTransaction(accNo, transaction_type, amount);
        }
        else if (choice==3){
          int acc1, acc2;
          string newname;
          cout << "enter account numbers of accounts to be merged:\n";
          cin >> acc1;
          cin >> acc2;
          cout << "enter Account Title of merged account: ";
          cin.ignore();
          getline(cin, newname);
          mybank.mergeAccounts(acc1, acc2, newname);
        }
        else{
          int acc1, acc2;
          int money;
          cout << "enter account numbers of accounts for money transfer:\n";
          cin >> acc1;
          cin >> acc2;
          cout << "enter amount to be transferred from first account to second account:\n";
          cin >> money;
          mybank.moneyTransfer(acc1, acc2, money);
        }
      }
    }
    else if (choice==3){
      int accNo;
      cout << "enter account number of account to be deleted: ";
      cin >> accNo;
      mybank.removeExistingAccount(accNo);
    }
    else{
      break;
    }
    mybank.displayBank();
  }
  cout << "you are out of bank program\n";
  //system("pause");
  return 0;
}
