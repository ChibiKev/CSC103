#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

int main() {
	/* print a frequency table for the strings we read
	 * from stdin. */
	string s; /* hold input */
	map<string,int> F; /* F[s] will store the count for s. */
	while (cin >> s) F[s]++;
	/* NOTE: it is crucial that integers are initialized
	 * to 0 here.  (Remember: integers that aren't part of a map
	 * are not initialized to 0 for you.) */
	for (map<string,int>::iterator i = F.begin(); i!=F.end(); i++) {
		cout << (*i).first << ":" << (*i).second << "\n";
		/* NOTE: *i actually has TWO parts: the key and the value.
		 * the key is stored in (*i).first, and the value is in
		 * (*i).second.  The picture in the notes might help you
		 * understand. */
		/* TODO: try to make sense out of the error message for this: */
		// cout << *i << endl;
	}
	/* to demonstrate that new values are initialized to 0: */
	// cout << "F[thing that wasn't in the map] == " << F["asdfasdfasdf"] << "\n";
	return 0;
}

/* TODO: re-write the above from scratch and make sure you understand
 * why it works. */

/* TODO: try to solve the same problem *WITHOUT* using maps!  Can you do
 * it with just vectors?  How about just sets?  */
/* TODO: if you managed to solve the above, estimate the number of
 * instructions your program will require to run on an input of n strings.
 * Then compare this with the solution using maps.  Note that M[s]++ takes
 * approximately log(n) steps if the map has n different strings. */
