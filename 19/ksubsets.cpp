#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;
#include <set>
using std::set;

/* TODO: write a function to compute all *k-subsets* of a given set.
 * Recall that k-subsets are subsets with *precisely* k elements.
 * Below are some function prototypes you could use.  See the notes
 * for the intuition and an outline. */

/* with sets: */
#if 0 //sets does not run
set<set<int> > ksubsets(set<int>& S, size_t k){
 size_t n= S.size();
 if (k >n) {
  return set <set<int> > ();
 }
 if (k==0) {
 return set <set<int> > (1,set<int> ());
 }
 set <int> ::iterator last = S.end();
 S.erase(*last-1);
 set <set<int> > L= ksubsets(S,k);
 set <set<int> > R= ksubsets(S,k-1);
 for (set<set<int> >::iterator i = R.begin(); i != R.end(); i++){
  set <int> T= *i;
  T.insert(*last-1);
  L.insert(T);
 }
 S.insert(*last-1);
 return L;
}
#else
/* or with vectors: */
vector<vector<int> > ksubsets(vector<int>& V, size_t k){
 size_t n= V.size();
 if (k >n) {
  return vector <vector<int> > ();
 }
 if (k==0) {
  return vector <vector<int>> (1,vector<int> ());
 }
 int last = V[n-1];
 V.pop_back();
 vector <vector<int> > L= ksubsets(V,k);
 vector <vector<int> > R= ksubsets(V,k-1);
 for (size_t i=0; i < R.size(); i++){
  vector <int> T= R[i];
  T.push_back(last);
  L.push_back(T);
 }
 V.push_back(last);
 return L;
}
#endif
int main()
{
	/* TODO: write some test code. */
 #if 0
 set <int> S= {1,2,3,4};
 int x;
 while (cin >> x){
 set<set<int> > P = ksubsets(S,x);
	for (set<set<int> >::iterator i = P.begin(); i != P.end(); i++) {
		cout << "{ ";
		for (set<int>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << "}\n";
   }
  }
 #else
  vector<int> S= {1,2,3,4};
  int x;
  while (cin >> x){
 	vector<vector<int> > P = ksubsets(S,x);
	for (vector<vector<int> >::iterator i = P.begin(); i != P.end(); i++) {
		cout << "{ ";
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << "}\n";
   }
  }
 #endif
	return 0;
}
