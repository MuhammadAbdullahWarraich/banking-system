#include "linkedlist.h"
#include <string>
class Bank{
  
  class Account{

    class Transaction{
      int id;
      string type;
      float transferredamount;
      int accountnumber;
    };
    List<Transaction> history;


  };
  List<Account> accounts;

};