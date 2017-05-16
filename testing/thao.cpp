#include <iostream>
using std::cout;
using std::cin;
int main(){
int wallet=0;
  cout<<"How many mesos do you have?\n";
  cin>>wallet;
if (wallet<=0)
  cout<<"You're Broke.\n";
else
  cout<<"You still have mulah.\n";
return 0;
}