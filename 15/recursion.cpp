#include <iostream>
using std::cout;

/* TODO: WITHOUT compiling and running this, see if you can predict
 * the output of f(4). */
void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	cout << n << " ";
	f(n-1);
	cout << n << " ";
}

/* TODO: write the factorial example from lecture. */
/* TODO: review mathematical induction, and if possible practice
 * some proofs.  */
/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */
/* TODO: write a function that recursively computes terms of the
 * fibonacci sequence.  Be careful -- it will likely be quite
 * slow on large inputs!  See if you can understand why.  */

/* TODO: try to implement the idea for recursive sorting from the lecture.
 * IDEA: sort the left and right halves recursively, then combine them
 * together with some kind of "merge" operation.
 * NOTE: this one might be a little tricky! */

int main(void)
{
	f(4);
	cout << "\n";
	return 0;
}
