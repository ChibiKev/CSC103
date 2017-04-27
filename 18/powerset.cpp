#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <set>
using std::set;
using namespace std;
/* TODO: try to re-write the powerset function from lecture. */

/* with sets: */
set<set<int> > powerSet(set<int>& S)
{
	/* check base case: */
	if (S.size() == 0) {
		set<int> empty;
		set<set<int> > P;
		P.insert(empty);
		return P;
	}
	int leftout = *S.begin();
	S.erase(leftout);
	/* Since S is now smaller, we can use recursive magic :D */
	set<set<int> > T = powerSet(S);
	/* store the "for real" powerset of S in P: */
	set<set<int> > P(T); /* copy T into P */
	/* At present, how is P deficient from the real powerset? */
	/* Answer: missing all subsets containing 'leftout' */
	/* Plan: for every set in T, add leftout, and then add
	 * the resulting set to P. */
	for (set<set<int> >::iterator i = T.begin(); i!=T.end(); i++) {
		set<int> U = *i;
		U.insert(leftout);
		P.insert(U);
	}
	return P;
}
/* NOTE: in the hand written notes, the "U" was supposed to denote
 * the union of sets, not another set as it is used above.  Just
 * in case that was confusing : ) */

/* TODO: try to write a powerset function for vectors, say using
 * the following prototype:  */
vector<vector<int> > powerSetV(vector<int>& V){
	if (V.size() == 0) {
		vector<int> empty;
		vector<vector<int> > P;
		P.push_back(empty);
		return P;
	}
	int leftout = *V.begin();
	V.erase(V.begin());
	vector<vector<int> > T = powerSetV(V);
	vector<vector<int> > P(T);
	for (vector<vector<int> >::iterator i = T.begin(); i!=T.end(); i++) {
		vector<int> U = *i;
		U.push_back(leftout);
		P.push_back(U);
	}
	return P;
}
/* For this, assume all elements of the vector are distinct. */

int main()
{
	/* TODO: test code goes here */
	set<int> S = {0,1,2};
	set<set<int> > P = powerSet(S);
	cout << "{\n";
	for (set<set<int> >::iterator i = P.begin(); i!=P.end(); i++) {
		cout << "  {";
		for (set<int>::iterator j = (*i).begin(); j!=(*i).end(); j++) {
			cout << *j << " ";
		}
		cout << "},\n";
	}
	cout << "}\n";
	vector <int> V = {0,1,2};
	vector<vector<int> > P1 = powerSetV(V);
	cout << "{\n";
	for (vector<vector<int> >::iterator i = P1.begin(); i!=P1.end(); i++) {
		cout << "  {";
		for (vector<int>::iterator j = (*i).begin(); j!=(*i).end(); j++) {
			cout << *j << " ";
		}
		cout << "},\n";
	}
	cout << "}\n";
	return 0;
}

/* TODO: try to finish the extended gcd (xgcd) algorithm from last time. */
