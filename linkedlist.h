#include <iostream>
using namespace std;
template <class T>
class List{
  Node* head;
  Node* tail;
  class Node{
  public:
    T data;
    Node* prev;
    Node* next;
  };
};