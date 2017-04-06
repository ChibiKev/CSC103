#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set> /* <-- new stuff. */
using std::set;
#include <string>
using std::string;
#include <cstdio>
#include <vector>
using namespace std;
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
void sort(vector<int>&x)
	{
		set<int> s;
		vector <int> k;
		for (vector<int>::iterator i=x.begin(); i != x.end(); i++)
			{s.insert(*i);}
		for (set<int>::iterator i=s.begin(); i!=s.end(); i++){
			k.push_back(*i);
		}
	x=k;
	}

/* exercise: compute the intersection of two sets:
 * recall that the intersection of two sets is the set
 * consisting of the elements they have in common.  E.g.,
 * intersection of {2,3,4,5,6,7} and {1,2,4,7,11,44} is
 * {2,4,7}
 * */
		/* TODO: write this. */
set<int> intersect(const set<int>& S1, const set<int>& S2) {
	set<int> change;
	for (set<int>::iterator i=S1.begin(); i !=S1.end(); i++){
		for (set<int>::iterator p=S2.begin(); p !=S2.end(); p++){
			if (*i==*p){
				change.insert(*i);
				break;
			}
		}
	}
		return change;
}
/* TODO: write a function that returns the union of two sets */
set<int>combine(set<int>s1,set<int>s2)
{
	set<int>add;
	for (set<int>::iterator i=s1.begin(); i!=s1.end();i++){
		add.insert(*i);
	}
	for (set<int>::iterator i=s2.begin(); i!=s2.end();i++){
		add.insert(*i);
	}
	return add;
}
/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */
int setinsert(vector<int> v, int x)
{
	bool find=true;
	for (vector<int>::iterator i=v.begin(); i!=v.end();i++){
			if (*i==x){
				find= false;
		}
	}
	return find;
}
/* TODO: write a function that removes a value from a vector if it
 * is present.  It should take a vector and a value x, and remove
 * x if it is in the vector. NOTE: you don't have to preserve the
 * order of the other elements! */
vector<int> remove (vector<int>v,int x){
	vector<int>update;
	for (vector<int>::iterator i= v.begin(); i < v.end(); i++){
		if (*i!=x){
			update.push_back(*i);
		}
	}
		return update;
	}

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
	#if 0 //checks if 1-10 is a square
	setTest();
	#endif
	#if 0 //prints out common factors in a set
	intTest();
	#endif
	#if 0 //comine 2 sets
	set<int> s1 = {1,2,3,4,5,6,7};
	set<int> s2 = {43,32,432,433,32,454,325,32};
	set<int>s3= combine(s1,s2);
	for (set<int>::iterator i = s3.begin(); i != s3.end(); i++){
		cout << *i <<endl;
	}
	#endif
	#if 0 //vector to set to vector
	vector<int> x;
	int y;
	while (cin >> y && y >= 0){
		x.push_back(y);
	}
	sort(x);
	for (size_t i=0; i < x.size();i++)
		{cout << x[i] << endl;}
	#endif
	#if 0//insert in stuff and not take duplicates
	vector<int> v;
	int x;
	while(cin >> x){
	if (setinsert(v,x))
	{
		v.push_back(x);
	}
	}
	cout << "the elements inside the vectors are: ";
	for (size_t i=0; i<v.size();i++){
		cout << v[i] << "  ";
	}
	#endif
	#if 1 //remove a number inside vector
	vector <int> t;
	int x;
	int n;
	cout << "insert any positive number" <<endl;
	while(cin>> x){
		t.push_back(x);
	}
	cin.clear();
	cout << "your vector contains" <<endl;
	for (size_t i=0; i < t.size(); i++){
		cout << t[i] << "  ";
	}
	cout << endl << "what do you want to remove from the vector?\n";
	cin >> n;
	cout << "it's been changed into" <<endl;
	t=remove(t,n);
	for (size_t i=0; i < t.size(); i++){
		cout << t[i] << "  ";
	}
	cout << endl;
	#endif
	return 0;
}
