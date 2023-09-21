#include "linkedlist.h"
#include <string>
#include <ctime>
class Bank{
  int acc_Serial;
  int trans_Serial;
  class Account{
    class Transaction{
    public:
      int transactionID;
      int transactionDate[3];//dd-mm-yyyy
      int transactionTime[3];//hh-mm-ss
      string transactionType;
      float transferredAmount;
      int accountNumber;
      Transaction(int id, string type, int transferredAmount, int accountNumber=-1){
        transactionID=id;
        transactionType=type;
        this->transferredAmount=transferredAmount;
        //this->accountNumber=accountNumber;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        time_t currentTime = time(0);
        tm* getTimeStuff=localtime(&currentTime);
        transactionDate[0]=getTimeStuff->tm_mday;
        transactionDate[1]=getTimeStuff->tm_mon;
        transactionDate[2]=getTimeStuff->tm_year;
        transactionDate[2]+=1900;
        transactionTime[0]=getTimeStuff->tm_hour;
        transactionTime[1]=getTimeStuff->tm_min;
        transactionTime[2]=getTimeStuff->tm_sec;
      }
      friend ostream& operator << (ostream& out, const Transaction& t){
        out << "Transaction ID: " << t.transactionID;
        out << "\nTransaction Date: " << t.transactionDate[0] << "-" << t.transactionDate[1] << "-" << t.transactionDate[2] << " (dd-mm-yyyy)";
        out << "\nTransaction Time: " << t.transactionTime[0] << ":" << t.transactionTime[1] << ":" << t.transactionTime[2] << " (hh:mm:ss)";
        out << "\nTransaction Type: " << t.transactionType;
        out << "\nTransferred Amount: " << t.transferredAmount;
        //out << "Account Number: " << t.accountNumber;//figure this out!!!!!!!!!!!!!!!!!!!!!!!!
      }
    };
    string accountTitle;
    int accountNumber;
    List<Transaction> transactionHistory;
    int accountBalance;
    public:
    void creditTransaction(int transactionID, int money){
      Transaction* temp=new Transaction(transactionID, "credit", money);
      transactionHistory.insertatTail(temp);
      accountBalance+=money;
    }
    void debitTransaction(int transactionID, int money){
      if (accountBalance>=money){
        Transaction* temp=new Transaction(transactionID, "debit", money);
        transactionHistory.insertatTail(temp);
        accountBalance-=money;
      }
      else{
        cout << "ERROR! You don't have enough balance to perform this transaction.";
      }
    }
     void displayAllDetails(){
      displayAccount();
      cout << "\n\nTransaction History:\n";
      transactionHistory.print("\n\n");
    }
    void displayAccount(){
      cout << "Account Title: " << accountTitle;
      cout << "\nAccount Number: " << accountNumber;
      cout << "\nAccount Balance: " << accountBalance;
    }
    Account(int accNo, string title){
      accountNumber=accNo;
      accountTitle=title;
    }
  };
  List<Account> accounts;
public:
  Bank(){
    acc_Serial=0;
    trans_Serial=0;
  }
  void addNewAccount(string title, int balance=0){
    Account* temp=new Account(acc_Serial, title);
    acc_Serial++;
    if (balance>0){
      temp->debitTransaction(trans_Serial, balance);
      trans_Serial++;
    }
  }
};