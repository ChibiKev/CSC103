#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set> /* <-- new stuff. */
using std::set;
#include <string>
using std::string;
#include <cstdio>

typedef set<int>::iterator si;
/* now you can type si instead of set<int>::iterator... */

void setTest() {
	/* store perfect squares in a set and then do some searches. */
	set<int> S;
	for (int i = 0; i < 10; i++) {
		S.insert(i*i);
	}
	int x;
	while (cin >> x) {
		if (S.find(x) != S.end()) {
			cout << x << " was a square.\n";
		} else {
			cout << x << " was not a square.\n";
		}
	}
	/* How to go through all elements of a set? */
	/* motivation: strange way to go through a vector / array: */
	int A[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int* i = &A[0]; i != &A[10]; i++) {
		cout << *i << endl;
	}
	/* NOTE: &A[0] gives a pointer to the first element. &A[10] gives
	 * a pointer to something *past the last element*.  This is very
	 * similar to the begin() / end() functions for iterators below: */
	/* here's the standard way to go through a set: */
	for (set<int>::iterator i = S.begin(); i != S.end(); i++) {
		cout << *i << endl;
	}
	/* NOTE: the elements come out in *sorted order*.
	 * TODO: write a sort function for vectors that just adds everything
	 * to a set, and then copies back to the vector. */
}

/* exercise: compute the intersection of two sets:
 * recall that the intersection of two sets is the set
 * consisting of the elements they have in common.  E.g.,
 * intersection of {2,3,4,5,6,7} and {1,2,4,7,11,44} is
 * {2,4,7}
 * */
set<int> intersect(const set<int>& S1, const set<int>& S2) {
	set<int> I;
	/* TODO: write this. */
	return I;
}

/* TODO: write a function that returns the union of two sets */

/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */

/* TODO: write a function that removes a value from a vector if it
 * is present.  It should take a vector and a value x, and remove
 * x if it is in the vector. NOTE: you don't have to preserve the
 * order of the other elements! */

void intTest() {
	set<int> s1 = {2,3,4,5,6,7};
	set<int> s2 = {1,2,4,7,11,44};
	set<int> s3 = intersect(s1,s2);
	cout << "intersection contained: ";
	for (set<int>::iterator i = s3.begin(); i != s3.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

/* NOTE: sets do not store duplicates: */

int main(void)
{
	intTest();
	// setTest();
	return 0;
}
