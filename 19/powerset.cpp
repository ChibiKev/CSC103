#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <set>
using std::set;

/* exercise: let's write the powerset function again, this time
 * with vectors instead of sets.  (We'll assume the vector has
 * unique elements.)  */

/* for ease of typing: */
typedef vector<int>::iterator vi;
typedef vector<vector<int> >::iterator vvi;

vector<vector<int> > powerSet(vector<int>& S){
	/* base case: S is empty: */
	if (S.size() == 0) {
		/* Return a vector containing the empty vector.  We'll use
		 * fancy constructors to make this nice and short: */
		return vector<vector<int> >(1,vector<int>());
		/* NOTE: the above says to return a (nameless!) vector containing one
		 * vector<int>, initialized with the default constructor, which will
		 * make it empty.  E.g., [[]].  A simpler example to understand:
		 * vector<int> V(10,23) would set V to have 10 copies of the value 23.
		 * */
	}
	/* now we'll use recursive magic to compute the powerset of
	 * something smaller -- in particular, S \ {<last element>} */
	int leftout = S.back();
	S.pop_back(); /* remove last element */
	vector<vector<int> > PS_prime = powerSet(S);
	/* NOTE: above is ok because S is now smaller by one element. */
	/* Now let's save a copy of powerset of S\{leftout}.  Every element
	 * will also be a part of our final answer -- we just need to add
	 * back copies of each element which also have leftout added. */
	vector<vector<int> > P(PS_prime); /* make P a copy of PS_prime. */
	/* at this moment, P contains all the subsets which don't have the
	 * element "leftout".  All that's left: add copies of each set in
	 * PS_prime with leftout added to them: */
	for (vvi i = PS_prime.begin(); i != PS_prime.end() ; i++) {
		/* each *i is a vector.  We want to add leftout to each one,
		 * and then add that whole thing back into P. */
		vector<int> T(*i); /* make a copy of *i */
		T.push_back(leftout); /* add leftout */
		P.push_back(T);
	}
	/* let's make this non-destructive of S (to be nice to the caller) */
	S.push_back(leftout);
	return P;
}

/* TODO: trace the above by hand on small-ish input (say a 3 or 4 element set).
 * Make sure you understand every detail.  Then trace it with gdb.  For this,
 * I would recommend compiling with `make -B debug`.  NOTE: I have disabled
 * optimization for the debug target.  Failing to do so might make the trace
 * a little confusing...  We'll go through this next class, but one command
 * in gdb that will be useful is 'bt' which prints the call stack. */

int main(){
	/* run a test: */
	vector<int> S = {1,2,3};
	vector<vector<int> > P = powerSet(S);
	for (vvi i = P.begin(); i != P.end(); i++) {
		cout << "{ ";
		for (vi j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << "}\n";
	}
	return 0;
}

/* TODO: try to finish the extended gcd algorithm from the notes. */
