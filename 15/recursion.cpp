#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
/* TODO: WITHOUT compiling and running this, see if you can predict
 * the output of f(4). */
void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	cout << n << " ";
	f(n-1);
	cout << n << " ";
}

/* TODO: write the factorial example from lecture. */
int factorial (int number){
	int temp;
	if (number<=1) return 1;
	temp = number * factorial(number-1);
	return temp;
}

/* TODO: review mathematical induction, and if possible practice
 * some proofs.  */
/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */
int power(int x, int n){
	if (n > 0) {
		return (power(x,n-1)*x);
	}
	else {
		return 1;
	}
}

/* TODO: write a function that recursively computes terms of the
 * fibonacci sequence.  Be careful -- it will likely be quite
 * slow on large inputs!  See if you can understand why.  */

int fibonacci(int number){
	if (number<2&& number>=0){
		return number;
	}
	else {
		return (fibonacci(number-1)+fibonacci(number-2));
	}
}

/* TODO: try to implement the idea for recursive sorting from the lecture.
 * IDEA: sort the left and right halves recursively, then combine them
 * together with some kind of "merge" operation.
 * NOTE: this one might be a little tricky! */
vector <int> sort(vector<int> &v){
	if (v.size()<2){
		return v;
		}
	else {
	vector <int> vleft(0,v.size()/2);
	vector <int> vright(v.size()/2+1,v.size());
	vleft=sort(vleft);
	vright=sort(vright);
	vector <int> sorted;
	size_t i=0;
	size_t j=0;
	while (i <=vleft.size() && j<=vright.size()){
		if (vleft[i] <= vright[j]){
		sorted.push_back(vleft[i]);
		i++;
		}
		else {
			sorted.push_back(vright[j]);
			j++;
		}
	}
	v=sorted;
}
return v;
}
int main(void)
{
	#if 0 //output of numbers
	f(4);
	cout << "\n";
	#endif
	#if 0 //factorial
	int code;
	cout << "insert factorial number" << endl;
	cin >> code;
	cout << code << "! = "<< factorial(code) <<endl;
	#endif
	#if 0 //power
	int x,n;
	cout << "enter number" << endl;
	cin >> x;
	cout << "enter power" << endl;
	cin >> n;
	cout << x << "^" << n << "=" << power(x,n) << endl;
	#endif
	#if 0 //fibonacci
	int number;
	cout << "insert number to run fibonacci sequence" << endl;
	cin >> number;
	cout << fibonacci(number) << endl;
	#endif
	#if 1 //sorting
	vector <int> sorting;
	int n;
	while (cin >> n){
		sorting.push_back(n);
	}
	sort(sorting);
	for (size_t i=0; i > sorting.size(); i++) {
		cout << sorting[i] << " ";
	}
	cout << endl;
	#endif
	return 0;
}
