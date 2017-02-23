/* Introducing vectors; more on functions. */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector> /* <--- new stuff */
using std::vector;
#include <cstdio>

/* TODO: write a function that takes a vector and searches
 * for a particular value x, returning true <==> x is found.
 * NOTE: you should think carefully about how to pass the parameters,
 * especially for the vector.  (By value, reference, const reference?) */

int main()
{
	/* TODO: read list of integers and print in reverse order.  (There
	 * is a solution outlined in the notes -- use a vector). */
	/* NOTE: remember that vector itself isn't a datatype.  It is like a
	 * machine that creates datatypes: */
	// vector v; /* won't compile -- vector isn't a type */

	#if 0
	/* TODO: figure out what is wrong with this version.  Note that we
	 * never use push back, but access elements directly. */
	int count = 0;
	while(cin >> s) {
		v[count] = s;
		count++;
	}
	/* NOTE: the above will compile, but it will break at *runtime* even
	 * on relatively small inputs.  For a hint, see capacity-test.cpp.  */
	#endif
	return 0;
}

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */

/* TODO: write a function that takes a vector and places the elements
 * in sorted order.  Warning: this could be kind of challenging. */
