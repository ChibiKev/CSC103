#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main (){
  int acnt=0, ecnt=0, icnt=0, ocnt=0, ucnt=0;
  char ch;
  while (cin >> ch) {
    switch(ch){
      case 'a':++acnt;break;
      case 'e':++ecnt;break;
      case 'i':++icnt;break;
      case 'o':++ocnt;break;
      case 'u':++ucnt;break;
    }
  }
  cout << "the appearance of a is " <<acnt<< endl;
  cout << "the appearance of e is " <<ecnt<< endl;
  cout << "the appearance of i is " <<icnt<< endl;
  cout << "the appearance of o is " <<ocnt<< endl;
  cout << "the appearance of u is " <<ucnt<< endl;
  return 0;
}