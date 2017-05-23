#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

//Sets
void sort(vector<int>&x) //Vector --> Set
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

set<int> intersect(const set<int>& S1, const set<int>& S2) { //Finding what's common in a set
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

set<int>combine(set<int>s1,set<int>s2) //Combining sets
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

int setinsert(vector<int> v, int x) //Check if something is found
{
	bool find=true;
	for (vector<int>::iterator i=v.begin(); i!=v.end();i++){
			if (*i==x){
				find= false;
		}
	}
	return find;
}

vector<int> remove (vector<int>v,int x){ //Remove value in vector
	vector<int>update;
	for (vector<int>::iterator i= v.begin(); i < v.end(); i++){
		if (*i!=x){
			update.push_back(*i);
		}
	}
		return update;
}
//Maps
void frequency (){ //Prints out "value (sorted) : number of times occured"
	string s;
	map<string,int> F;
	while (cin >> s) F[s]++;
	for (map<string,int>::iterator i = F.begin(); i!=F.end(); i++) {
		cout << (*i).first << ":" << (*i).second << "\n";
	}
}

//Recursion *CRITICAL*
int factorial (int number){ //Returns the factorial of the number
	int temp;
	if (number<=1) return 1;
	temp = number * factorial(number-1);
	return temp;
}

int power(int x, int n){ //Returns a power of the number
	if (n > 0) {
		return (power(x,n-1)*x);
	}
	else {
		return 1;
	}
}
#if 0 //Returns the fibonacci sequence of the number, 1 for regular, 0 for storage
int fibonacci(int number){
	if (number<2&& number>=0){
		return number;
	}
	else {
		return (fibonacci(number-1)+fibonacci(number-2));
	}
}
#else
int fibonacci(size_t x, vector <int> &n){
	if (x < n.size()) {
		return n[x];
	}
	size_t answer=0;
	if (x<=1&& x>0) {
		answer=1;n.push_back(0);
	}
	else if (x<=0){
		answer=0;
	}
	else{
		answer=(fibonacci(x-1,n) + fibonacci(x-2,n));
	}
	n.push_back(answer);
	return answer;
}
#endif

#if 0 //Sort=1, Mergesort=0
vector <int> sort(vector<int> &v){ //Sorting
	if (v.size()<2){
		return v;
		}
	else {
	vector <int> vleft;
	vector <int> vright;
		for (size_t i=0; i < v.size(); i++){
			if (i < v.size()/2){
				vleft.push_back(v[i]);
			}
			else {
				vright.push_back(v[i]);
			}
		}
	sort(vleft);
	sort(vright);
	vector <int> sorted;
	size_t i=0;
	size_t j=0;
	while (i < vleft.size() && j<vright.size()){
		if (vleft[i] < vright[j]){
		sorted.push_back(vleft[i]);
			i++;
		}
		else {
			sorted.push_back(vright[j]);
			j++;
		}
	}
	while (i < vleft.size()) sorted.push_back(vleft[i++]);
	while (j < vright.size()) sorted.push_back(vright[j++]);
	v=sorted;
	}
	return v;
}
#else
void merge(vector<int>& A, size_t low, size_t mid, size_t high)
{
	vector<int> merged;
	size_t l=low; /* left subarray candidate for smallest element */
	size_t r=mid+1; /* right subarray candidate for smallest element */
	while (l <= mid && r <= high) {
		if (A[l] <= A[r]){
			merged.push_back(A[l++]);
		}
		else{
			merged.push_back(A[r++]);
		}
	}
  if (l > mid){
    for (size_t x=r; x<=high; x++){
      merged.push_back(A[x]);
    }
  }
  else {
    for (size_t x=l; x<=mid; x++){
    merged.push_back(A[x]);
    }
  }
  for (size_t i= low; i <= high; i++) {
  A[i]=merged[i-low];
  }
}

void mergeSort(vector<int>& A, size_t low, size_t high)
{
	if (low >= high) return;
	size_t mid = (low+high) / 2;
	mergeSort(A,low,mid);
	mergeSort(A,mid+1,high);
	merge(A,low,mid,high);
}
#endif

void printVertically(unsigned long n) //Vertical Printing
{
	// your code goes here.
	if (n < 10){
		cout << n << endl;
	}
	else {
		printVertically(n/10);
		cout << (n%10) << endl;
	}
}

int gcd(int a, int b) //Finding gcd
{
	if (b==0) {
		return a;
	}
	else
	return gcd (b, a%b);
}

int xgcd(int a, int b, int& u, int& v) //Extending gcd
{
	if (a==0){
		u=0;
		v=1;
		return b;
	}
	int x, y;
	int z= xgcd (b%a, a, x, y);
	u= y- (b/a) * x;
	v= x;
	return z;
}

set<set<int> > powerSet(set<int>& S) //Powerset using Sets
{
	if (S.size() == 0) {
		set<int> empty;
		set<set<int> > P;
		P.insert(empty);
		return P;
	}
	int leftout = *S.begin();
	S.erase(leftout);
	set<set<int> > T = powerSet(S);
	set<set<int> > P(T);
	for (set<set<int> >::iterator i = T.begin(); i!=T.end(); i++) {
		set<int> U = *i;
		U.insert(leftout);
		P.insert(U);
	}
	return P;
}

vector <vector<int> > powerSetV (vector <int> &s){ //Powerset using Vecotrs
	vector <vector <int> > res;
	if (s.size()==0){
		res.push_back(vector<int> () );
		return res;
	}
	int tmp=s.back();
	s.pop_back();
	res=powerSetV(s);
	size_t n=res.size();
	for (size_t i=0; i < n; i++){
		vector <int> v=res[i];
		v.push_back(tmp);
		res.push_back(v);
	}
	s.push_back(tmp);
	return res;
}

#if 0 //finding the Ksubset, 1 for set, 0 for vector.
set<set<int> > ksubsets(set<int>& S, size_t k){
 size_t n= S.size();
 if (k >n) {
  return set <set<int> > ();
 }
 if (k==0) {
  set <set<int> > P;
  P.insert(set<int> ());
  return P;
 }
 int first= *(S.begin());
 S.erase(S.begin());
 set <set<int> > L= ksubsets(S,k);
 set <set<int> > R= ksubsets(S,k-1);
 for (set<set<int> >::iterator i = R.begin(); i != R.end(); i++){
  set <int> T= (*i);
  T.insert(first);
  L.insert(T);
 }
 S.insert(first);
 return L;
}
#else
vector<vector<int> > ksubsets(vector<int>& V, size_t k){
 size_t n= V.size();
 if (k >n) {
  return vector <vector<int> > ();
 }
 if (k==0) {
  return vector <vector<int> > (1,vector<int> ());
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

vector<vector<int> > perms(vector<int> V) //Finding all possible combinations of V, permuation
{
	if (V.size() == 1) return vector<vector<int> >(1,V);
	vector<vector<int> > R;
	for (size_t i = 0; i < V.size(); i++) {
		int last = V[i];
		V[i] = V[V.size()-1];
		V.pop_back();
		vector<vector<int> > T = perms(V);
		for (size_t j = 0; j < T.size(); j++) {
			T[j].push_back(last);
			R.push_back(T[j]);
		}
		V.push_back(V[i]);
		V[i] = last;
	}
	return R;
}

int main(){
	cout << "Testing it is a bit hard but the functions all all in this file" << endl;
	return 0;
}