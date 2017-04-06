/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>
#include <cmath>

int main()
{
	/* BIG PICTURE IDEAS WITH LOOPS.
	 * 1. "Brute force" -- leverage the speed of the computer to explicitly
	 *    run through an entire space of potential solutions, checking
	 *    each candidate for validity.  This is usually pretty trivial.
	 * 2. Maintaining invariants -- when computing some aggregate function
	 *    of a long list of inputs, initialize a variable to be something
	 *    like "the right answer so far" and then read new inputs one by
	 *    one, *updating your candidate answer* so that after each iteration
	 *    of the loop, it is ALWAYS the "right answer so far".
	 * NOTE: even brute force typically has an invariant hiding somewhere, but
	 * it usually isn't all that interesting.
	 * Let's see some examples: */

	/* exercise: compute the min of integers supplied via stdin. */
	#if 0
	int n; /* store input */
	int min; /* minimum of what we've seen3 *so far*. */
	cin >> n;
	min = n; /* NOTE: at this point, min's value is
				consistent with the meaning we gave it! */
	while (cin >> n) {
		if (n < min) min = n;
		/* NOTE: the *invariant* for this loop is that
		 * min is the smallest value we've read so far.
		 * Initialize min to have this property before the
		 * loop, and then at the end of each iteration, make
		 * sure this property remains true (it's *invariant*).
		 * */
	}
	cout << min << "\n";
	return 0;
	#endif

	/* TODO: if you haven't already, be sure you can do this on your own,
	 * as well as similar things like the min, the sum, the product, the
	 * average...  Try to take the following very high level steps:
	 * 1. First, think about how many variables you will need, and for what
	 *    purposes.
	 * 2. Declare the variables, and in comments, state the meaning of each
	 *    variable.
	 * 3. Loop through the input and make sure the meaning of each of your
	 *    variables is preserved at the end of each iteration of the loop.
	 * 4. Finally, print the results.
	 * */
#if 0
int x,count=1,y, average;
cin >> x;
y=x;
while (cin >> x){
	y+=x; count++;
}
average=y/count;
cout << average << endl;
#endif
	/* exercise: brute force gcd.  Compute the greatest common
	 * divisor of n and k by an exhaustive search.  */
	/* IDEA: start with the largest possible value that the gcd
	 * could have, then walk *backwards* until you find the first
	 * value that divides both inputs. */
	/* Range of possibilities for a valid answer: {min{a,b}...1} */
	#if 0
	int a,b; /* store the input */
	cin >> a;
	cin >> b;
	/* to make life easier, let's force a to be the smallest one.
	 * So, we swap the contents if needed: */
	if (a > b) { /* need to swap the contents a <--> b */
		int t = a; /* save old value of a */
		a = b;
		b = t;
	}
	/* now we know for sure a <= b */
	for (int i = a; i >= 1; i--) {
		/* test if i is a common divisor.  The first one
		 * we find will be the gcd, since we started from
		 * the largest possible value. */
		if (b % i == 0 && a % i == 0) { /* test if i divides both a and b */
			printf("gcd(%i,%i) == %i\n",a,b,i);
			break;
		}
	}
	return 0;
#endif
	/* TODO: brute force test for perfect cubes.  Check if
	 * n = k^3 for some integer k.  */
#if 0
int n;
	while(cin >> n){
	for (int x=n-1; x > 0; x--) {
		if (n%(x*x*x)==0){
			cout << n << "=" << x << "^3" << endl;
			break;
		}
	}
}
#endif
	/* TODO: write a loop that prints the sum of the first n odd cubes. */
#if 1
int x,y; //x is the input value;y is the cubed variable
	while(cin >> x){ //endless input
		int z=0; //z is the sum
		for(int count=1,max=x;count<=max;count++){ //count goes through every value up until max=input;
			y=pow(count,3); //equates y to count^3
				if (y%2!=0){ //if y is odd, returns true
					z+=y; //adds the odd cubed value into z
					cout<<"z="<<z-y<<'+'<<cbrt(y)<<"^3"<<endl; //Just testing
				}
				else //if y is even
					max++; //max is increased, since a value has not been input into z during this loop
		}
		cout<<"The sum of the first "<<x<<" odd cubes is "<<z<<".\n"; //output value
		//Based on the output results, all odd numbers will give an odd cubed value
		//And all even numbers will give an even cubed value
		//It's probably possible to make the program even shorter using . . .
		/*

		int x; //x is the input value;
	while(cin >> x){ //endless input
		int z=0; //z is the sum
		for(int count=1,max=x;count<=max;count+2){ //count goes through every odd value up until max;
					z+=pow(count,3); //adds the odd cubed value into z
					cout<<"z="<<z-y<<'+'<<cbrt(y)<<"^3"<<endl; //Just testing
				}
		}
		cout<<"The sum of the first "<<x<<" odd cubes is "<<z<<".\n"; //output value

		*/
}
#endif
	/* TODO: write code that gets an integer n from the user and prints out
	 * the n-th term of the fibonacci sequence. */
#if 0
int start=0, x, y=1, count=0, next=0;
for (cin >> x;x>count;count++){
	next=start+y;
	start=y;
	y=next;
}
	cout << start << endl;

#endif
	/* TODO: a slight generalization of an earlier exercise: for integers
	 * n and k, determine the largest power of k that divides n. */
#if 0
int n;
cin >> n;
for (cin >> n)


#endif

	/* TODO: write a program that reads (arbitrarily many) integers from
	 * stdin and outputs the *second* smallest one.  NOTE: you don't need
	 * to store many numbers (all at once, that is) to do this!  You'll
	 * only need a few integer variables.  Think about invariants! */
#if 0
int x,min,secondmin;
cin >> min;
cin >> secondmin;
if (min > secondmin)
{
	min=secondmin;
}
while (cin >> x){
	if (min > x){
		secondmin=min;
		min=x;
	}
	}
	cout << secondmin << endl;
#endif
	return 0;
}

// vim:foldlevel=1
