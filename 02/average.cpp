/* read 3 integers from standard input, print the average. */
#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int a,b;
	cout << "Input first number\n";
	cin >> a; /* read an integer into a. */
	b=a;
	cout << "Input second number\n";
	cin >> a;
	b+=a;
	cout << "Input third number \n";
	cin >> a;
	b+=a;
	cout << "Input fourth number \n";
	cin >> a;
	b+=a;
	cout << "Input fifth number \n";
	cin >> a;
	b+=a;
	/* TODO: finish this program (it should just print the average). */
	/* TODO: test this program.  Try typing the input manually, but also
	 * try this:
	 * $ echo 2 3 5 | ./average */
	/* TODO: extend this program to take the average of 5 integers,
	 * and do so *ONLY USING TWO VARIABLES TOTAL*. */

	cout << "Your average is " << b/5 << "\n";



	return 0;
}

/* NOTE: to compile this, try $ g++ -o average average.cpp
 * Then the executable will be named "average" instead of "a.out". */
