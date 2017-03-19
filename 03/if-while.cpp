/* Flow of control:
 * Boolean expressions; if and while statements.
 * */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main()
{
	/* IF STATEMENTS */

	/* IDEA: execute a piece of code 0 or 1 times, conditioned upon a
	 * boolean expression.
	 * */
	#if 0 /* NOTE: replace 1 with 0 to comment everything until
			 the endif below */
	cout << "Did you remember your umbrella? ";
	string answer; /* NOTE: string is for sequences of characters.
					  e.g., "hello how are you?" */
	cin >> answer;
	/* output a response based on the answer we get: */
	// if (answer == ("no" || "NO")) {
	// TODO: try the above version.  Observe the horrible error
	// message...  O_O
	if (answer == "no" || answer == "NO") {
		cout << "T_T\n";
	} else {
		cout << "I envy you.\n";
	}
	#endif

	/* general form:
	 * if (<boolean expression>) {
	 *     statements...
	 * } else if (<boolean expression>) {
	 *     more statements...
	 * } else {
	 *     statements if all other cases failed...
	 * }
	 * NOTE: exactly ONE of the blocks of statements will be excuted: that
	 * of the first "match" (true expression), or the else at the end.
	 * */

	/* NOTE: TWO equals signs (==) are needed to test equality.
	 * Otherwise you'll end up doing assignment. */
	/* TODO: write an example where = is used when == was intended.
	 * Make sure you understand the behavior of the program, and also
	 * take a look at the compiler output -- it should at least give
	 * you a warning. */

	/* Boolean expressions: expressions that can evaluate to either
	 * true or false.  For example, x == 3, or response != "yes".
	 * other (binary) boolean operators:
	 * ==
	 * !=
	 * <
	 * >
	 * <=
	 * >=
	 * The above work on integers, strings, chars, and lots more.
	 * Furthermore, we have the following operators on booleans:
	 * && -- this gives the logical "and"
	 * || -- this gives the logical "or"
	 * !  -- this gives the logical negation
	 * */


	/* LOOPS */

	#if 0
	/* infinite loop! */
	while (true) {
		cout << "@_@  @_@  @_@  ";
	}
	/* NOTE: hit ctrl-c to stop this program. */
	#endif
	/* now something actually useful. */
	/* quick warm up: print all integers squares less than 100.
	 * e.g., 0,1,4,9,16,25... */
	#if 0
	int i = 0; /* Remember: 1 equals sign means "assignment".
	                        2 equals signs is the boolean comparison */
	while (i < 10) {
		cout << i*i << "\n";
		i = i+1; /* shorthand: i++ */
	}
	cout << "i == " << i << "\n"; /* prints 10, not 9! */
#endif
 #if 0
 int x,n;
 cin >> x;
 n=x;
 while (cin >> x) {
	 if (n > x)
		 n=x;
 }
	 cout << "min:" << n << endl;
#endif
	/* general form:
	 * while (<boolean expression>) {
	 *    statements to do while expression is true...
	 * }
	 * */

	/* TODO: read integers from stdin, and print out the smallest one.
	 * (hint: use a loop like this: "while(cin >> n) {...}" where n is
	 * an integer variable. The loop will break when stdin is exhausted.
	 * If you are typing in numbers manually, you can end the input with
	 * ctrl-d.  Example:
	 * $ ./if-while
	 * 3 4 9 2 9 1 <hit enter>
	 * <hit ctrl-d>
	 * min == 1
	 * */
#if 0
int x,n;
cin >> x;
n=x;
while (cin >> x) {
	n+=x;
}
	cout << "sum=" << n << endl;
#endif
/* TODO: read integers from stdin, and print their sum.  See above
	 * for how to read ints from stdin (use a while(cin >> n) thing). */
int n,x;
cin >> n;
x=n;
int count=0;
for (cin >> n; n%2==0; count++){
	n=n/2;
}

	cout << "2**" << count << "=" << x <<endl;
	cout << count << endl;

	/* TODO: given an integer n, find exponent of the largest power of two that
	 * divides n.  Example: if n = r*8 with r odd, then you should output 3
	 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
	 * number's factorization into primes.) */
	/* IDEA: keep on dividing n by two until we can't,
	 * and keep track of how many times it worked. */


	return 0;
}

/* TODO: compile this via the makefile instead of typing out the g++
 * commands yourself.  */

// vim:foldlevel=1
