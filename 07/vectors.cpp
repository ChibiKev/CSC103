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
#if 0
int f(vector<int> n, int x){
	int find=x;
	for (size_t i=0; i < n.size()-1; i++){
		if (find==n[i])
			return true;
	}
}
int main(){
	int y;
	int x;
	vector <int> t;
	cout << "What are you looking for?" << endl;
	cin >> x;
	cout << "what are the values?" << endl;
	while (cin >> y) {
		t.push_back(y);
	}
	for (size_t i=0; i< t.size()-1; i++){
		cout << f(t,x) << endl;
	}
	return 0;
}
#endif
	/* TODO: read list of integers and print in reverse order.  (There
	 * is a solution outlined in the notes -- use a vector). */
	/* NOTE: remember that vector itself isn't a datatype.  It is like a
	 * machine that creates datatypes: */
	// vector v; /* won't compile -- vector isn't a type */

#if 0
int main (){
	int n;
	vector <int> v;
	while (cin>>n){
		v.push_back(n);
	}
	for (int i=v.size()-1; i>=0;i--)
	cout << v[i] << endl;
#endif
#if 1 //work on this
	/* TODO: figure out what is wrong with this version.  Note that we
	 * never use push back, but access elements directly. */
int main(){
	int s;
	vector <int> v;
	int count = 0;
	while(cin >> s) {
		v[count] = s;
		count++;
	}
	return 0;
}
	/* NOTE: the above will compile, but it will break at *runtime* even
	 * on relatively small inputs.  For a hint, see capacity-test.cpp.  */
#endif

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
