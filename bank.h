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
        this->accountNumber=accountNumber;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
    };
    string accountTitle;
    int accountNumber;
    List<Transaction> transactionHistory;
    int accountBalance;
    void creditTransaction(int transactionID, int money){
      Transaction* temp=new Transaction(transactionID, "credit", money);
      transactionHistory.insertatTail(temp);
      accountBalance+=money;
    }
  };
  List<Account> accounts;
public:
  Bank(){
    acc_Serial=0;
    trans_Serial=0;
  }
};