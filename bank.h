#include "linkedlist.h"
#include <string>
class Bank{
  class Account{
    class Transaction{
    public:
      int transactionID;
      
      string type;
      float transferredamount;
      int accountnumber;
      Transaction(int id){
        transactionID=id;
        
      }
    };
    string accountTitle;
    int accountNumber;
    List<Transaction> transactionHistory;
    int accountBalance;
  };
  List<Account> accounts;
  int acc_Serial;
  int trans_Serial;
public:
  Bank(){
    acc_Serial=0;
    trans_Serial=0;
  }
};