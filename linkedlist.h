#pragma once
#include <iostream>
using namespace std;
template <class T>
class List {
private:
class Node {
public:
T data;
Node* next;
Node* prev;
};
Node* head;
Node* tail;
public:
List() {
head = new Node;
tail = new Node;
head->next = tail;
tail->prev = head;
tail->next = nullptr;
head->prev = nullptr;
}

class Iterator {
private:

Node* curr;

public:

Iterator(Node* n = nullptr)
{ curr = n; }
Iterator(Iterator& rhs)
{ curr = rhs.curr; }
Iterator & operator++() {
curr = curr->next;
return *this;

}

Iterator& operator--() {
curr = curr->prev;
return *this;
}

bool operator==(const Iterator& rhs)const {

if (curr == rhs.curr)
return true;
else return false;

}
bool operator!=(const Iterator& rhs)const {

if (curr != rhs.curr)
return true;
else return false;

}
T& operator*() {

return curr->data;

}
};

Iterator begin() {

Iterator itr(head->next);
return itr;

}
Iterator end() {

Iterator itr(tail);
return itr;

}
void print(string separator="->") {

Iterator itr;
for (itr = begin();itr != end();itr++)

cout << *(itr) << separator;

}
cout << "\n";
Iterator insert(Iterator it, T d)
{
Node* p = it.curr;
Node* t = new Node;
t->data = d;
t->prev = p->prev;
t->next = p;
p->prev->next = t;
p->prev = t;
Iterator ret(t);
return ret;
}
void insertatHead(T d) {
Iterator it(head->next);
insert(it, d);
}
void insertatTail(T d) {
Iterator it(tail);
insert(it, d);
}
};