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
#if 1
vector <int> sort(vector<int> &v){
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
void Merge(vector<int> & vec, vector<int> & v1, vector<int> & v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (v1[p1] < v2[p2]) {
            vec.push_back(v1[p1++]);
        } else {
        vec.push_back(v2[p2++]);
        }
    }
    while (p1 < n1) vec.push_back(v1[p1++]);
    while (p2 < n2) vec.push_back(v2[p2++]);
}

void Sort(vector<int> & vec) {
    int n = vec.size();
    if (n <= 1) return;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            v1.push_back(vec[i]);
        } else {
        v2.push_back(vec[i]);
        }
    }
    Sort(v1);
    Sort(v2);
    vec.clear();
    Merge(vec, v1, v2);
}
#endif

int main(void)
{
	#if 0 //output of numbers
	f(4);
	cout << "\n";
	#endif
	#if 1 //factorial
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
	#if 0 //sorting
	vector <int> sorting;
	int n;
	while (cin >> n){
		sorting.push_back(n);
	}
	sort(sorting);
	for (size_t i=0; i < sorting.size(); i++) {
		cout << sorting[i] << " ";
	}
	cout << endl;
	#endif
	return 0;
}
