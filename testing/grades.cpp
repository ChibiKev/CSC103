#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main (){
  int grade;
  char Lettergrade;
  cout << "Insert Grade\n";
  cin >> grade;
  if (grade<=60)
  Lettergrade='F';
  else if (grade <= 70)
    Lettergrade='D';
  else if (grade<=80)
    Lettergrade='C';
  else if (grade <=90)
    Lettergrade='B';
  else Lettergrade='A';
  cout << "You're grade is " << Lettergrade << endl;
  return 0;
}