/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Collatz conjecture: for all integers n, the following process
	 * will terminate in a finite number of steps:
	 *    if n == 1, stop;
	 *    if n is even, divide by 2;
	 *    if n is odd, multiply by 3 and add 1;
	 *    repeat using this new value of n.
	 * */
	/* let's test the conjecture for many integers, provided on
	 * standard input. */
	#if 0
	int n;
	while (cin >> n) {
		int oldn = n;
		int count = 0;
		while (n > 1) {
			count++;
			if (n % 2 == 0) n /= 2; /* NOTE: n/=2 is shorthand for n = n/2 */
			else n = n*3 + 1;
		}
		cout << oldn << " stopped after " << count << " steps.\n";
	}

	return 0;
}
#endif
/* TODO: delete the entire thing and rewrite it from scratch. */
#if 0
int n;
int count=0;
while (cin >> n){
	while (n>1){
	count++;
	if (n%2==0)
		n/=2;
	else
		n=(n*3)+1;
	}
cout << count << endl;
}
#endif
/* TODO: look through the bash-history and see how much makes sense. */
/* NOTE: if (and ONLY IF) you are feeling ambitious, try to make sense
 * out of this shell pipeline, which also finds the maximal # of steps
 * for collatz, but does so without using sort, pushing more work into
 * the awk program:
 * echo {1..500} | ./collatz | awk 'BEGIN{x=0} {if ($4 > x) x=$4;} END{print x}'
 * This version is more "efficient" in that it does not require sorting the
 * entire input, or even *storing* the entire input at once.
 * */
return 0;
}
// vim:foldlevel=1
