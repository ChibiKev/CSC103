/* Lucas sequences. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Lucas sequences (of the first kind):
	 * U_n(P,Q) = P*U_{n-1}(P,Q) - Q*U_{n-2}(P,Q).
	 * The first two terms are defined as 0 and 1, respectively.
	 * */
	/* TODO: write this.  Try not to just copy what's in the outline
	 * in the notes, but instead try it from scratch first! Also, make
	 * sure your code works for small values of n (0 and 1 in particular).
	 * */

	int n,i=1;
	cin >> n;
	int oneb4=1, twob4=0, current=1;
	while(i<n){
		i++;
		twob4=oneb4;
		oneb4=current;
		current=oneb4-twob4;
	}
	cout<<current<<endl;
	return 0;
}

// vim:foldlevel=1
#if 0

int n;
cin >> n;
int onebefore=2,twobefore=3, current=14;
int i=2;
while (i<n) {
	i++;
	twobefore=onebefore;
	onebefore=current;
	current=5*onebefore+2*twobefore-i;
}
cout << current << endl;
return 0;
}
#endif