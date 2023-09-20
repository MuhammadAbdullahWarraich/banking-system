#include <iostream>
#include <stack>
using namespace std;
bool checkString(string checkme){
  stack<char> brackets;
  for (int i=0;i<checkme.length();i++){
    if (brackets.empty()){
      brackets.push(checkme[i]);
    }
    else if ((brackets.top()==char(40) && checkme[i] == char(41))
     || (brackets.top()==char(123) && checkme[i] == char(125))
      || (brackets.top()==char(91) && checkme[i] == char(93))){
      brackets.pop();
    }
    else {
      brackets.push(checkme[i]);
    }
  }
  if (brackets.empty()){
    return true;
  }
  return false;
}
void printMessage(string expression){
  if (checkString(expression)){
    cout <<  expression << " balanced braces\n";
  }
  else{
    cout << expression << " not balanced braces\n";
  }

}
int main(){
 printMessage("(())");
 printMessage("()(()())))");

 system("pause");
 return 0;
}