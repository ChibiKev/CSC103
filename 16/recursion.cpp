#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
int fibonacci(size_t x, vector <int> &n);
/* Let's revisit our example from last class: */
void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	#if 0
	cout << n << " ";
	f(n-1);
	#else
	f(n-1);
	cout << n << " ";
	#endif
	/* TODO: make sure you can trace the sequence of recursive calls that
	 * would result from calling say, f(3).  Flip the order of the cout
	 * statement and the recursive call, and make sure you understand
	 * the output in both cases. */
}

// TODO: write a recursive function that prints the base 10 digits of n
// vertically to cout.  for example, printVertically(2358) would print
// 2
// 3
// 5
// 8
// Rules: you can't use any loops.  You can't use vectors or arrays.
// Just let the recursive function calls do the work for you.
void printVertically(unsigned long n)
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

// TODO: write a recursive function to compute a^b (a to the b power)
int power(int x, int n){
	if (n > 0) {
		return (power(x,n-1)*x);
	}
	else {
		return 1;
	}
}
/* binary search. */
bool search(int* A, int size, int x)
{
	/* TODO: try to turn the following "plain-English" procedure into
	 * a recursive program:
	 * 1. if the array is empty (size < 1) return false.
	 * 2. if x is less than the value in the middle, recursively search
	 *    the left subarray, else recursively search the right subarray.
	 * Test out your program, and try to prove (by induction) that it works.
	 * (There are some subtle points about making sure the size is always
	 * decreasing...)
	 * */
#if 1
	size_t mid= size/2;
	if (size < 1)
		return false;
	else if (x==A[mid]){
		return true;
	}
	else{
		int L[mid];
		int R[mid];
		for(size_t i=0;i<mid;i++){
			L[i]=A[i];
		}
		for(size_t i=0;i < mid;i++){
				R[i]=A[mid+1+i];
		}
			if (x< A[mid]){
			search (L,mid,x);
			}
			else if (x > A[mid]){
			search (R,mid,x);
			}
	}
#else
	if (size<1) {
		return false;
	}
	size_t mid= size/2;
	size_t leftmid=mid/2;
	size_t rightmid=mid+leftmid;
	if (x==A[mid]) {
		return true;
	}
	int truth= (int) search (A,leftmid,x) + (int) search (A,rightmid,x);
	if (truth){
		return true;
	}
	return false;
#endif
}
int main()
{
	f(4);
	/* TODO: write test code for your functions. */
	printVertically(3227);
	/* binary search test: */
	#if 0
	int A[100];
	for (size_t i = 0; i < 100; i++) {
		A[i] = i*i;
	}
	int x;
	while (cin >> x)
		cout << search(A,100,x) << endl;
	#endif
	#if 1
	vector<int> n;
	int x;
	while (cin >> x){
	cout << fibonacci(x,n);
	cout << endl;
	}
	#endif
	return 0;
}

/* TODO: try to write the "memoized" version of fibonacci we outlined
 * during lecture.  NOTE: there are some slightly annoying details if
 * you use vectors.  Maps might be a bit easier. */
int fibonacci(size_t x, vector <int> &n){
	// invariant: if n < n.size
	// then n[x]==f(x)
	n={0,1,1,2};
	if (x < n.size()) {
		return n[x];
	}
	size_t answer=0;
	if (x<2&&x>0) {
		answer=1;
		n.push_back(answer);
	}
	else{
		answer=(fibonacci(x-1,n) + fibonacci(x-2,n));
		//update memory/table of answers
		//need to set n[x]=answer, but
		//be careful to make sure there is space,
		//of note, pushback might add
		//element in the wrong answer
		if (answer>1){
		n.push_back(answer);
		}
	}
	return answer;
}