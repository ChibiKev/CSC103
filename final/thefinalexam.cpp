These are the questions from the CSC 103 Spring 2017 Final.

Question 1- 8 Points

Write a function that takes an input of (x,y) and create a box
for example, (5,3)
creates:
* * * * *
*       *
* * * * *

How I wrote it:
#include <iostream>
#include <string>
using namespace std;

void box (int x, int y){
    for (int count=1; count <= x; count++){
        if (count==1 || count==x){
            for (int i=1; i <= y; i++){
            cout << "* ";
            }
        }
        else if (count != x && count != 1){
            for (int i=1; i<=y; i++){
                if (i==1 || i==y){
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}
int main()
{
  box(6,4);
  return 0;
}

Question 2- 8 Points

Write a function that takes in a string and a character and pushes the character to the back
for example, "character" takes "c" and returns "haratercc"

Question 3- 8 Points

There were three parts to this, all dealing with the last 2 lectures, with dynamic memory and using new and delete.
A) Write a line of code that allocates an array with 10 elements
B) Write a line of code to remove the allocation from a)
C) Write a few lines of code to double the size of the allicated array. Use A and B.

Question 4- 5 Points

Create a recursive function for verticalprinting.
For example, 4534 would be printed as
4
5
3
4

Question 5- 8 Points

Write codes for counting the amount of times a word has appeared, frequency table. Maps is already included in the library.
For example, This is the black black cat.
This  1
is    1
the   1
black 2
cat   1

Question 6- 4 Points

Write out the output of this function that takes mysteryprint(3,2):

void mysteryprint(int n, int k){
  int i;
  for (i=0; i < n-k; i++){
    cout << "*";
  }
  for (i=0; i < n+k; i++){
    cout << ".";
  }
  cout << "\n";
  if (k==0){
    return;
  }
  mysteryprint(n,k-1);
  for (i=0; i < n+k; i++){
    cout << "*";
  }
  for (i=0; i < n-k; i++){
    cout << ".";
  }
  cout << "\n";
}

Question 7- 5 Points

Create a recursive function for GCD.

Question 8- 5 Points

Create a function for a binary search. By using the first element and last element and the midpoint to see which is greater. Assume, its all sorted.

Question 9- 5 Points, Extra Credit

I cant remember this one well, it has something to deal with counting the amount of steps it takes to proform a task so its reduced to log 2 amount of times.

Total Points is 51.