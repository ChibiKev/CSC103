#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

/* TODO: try to reproduce this entire thing on your own. */

/* merge two sorted arrays into one */
void merge(vector<int>& A, size_t low, size_t mid, size_t high){
	/* our job here: given that A[low..mid] and A[mid+1..high]
	 * are sorted, fill A[low..high] with their contents in
	 * sorted order.  IDEA: keep in mind that thing with the
	 * stacks of cards... */
	vector<int> merged; /* store sorted / merged output to then
						   copy back into A. */
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
	/* TODO: now handle case where one or the other has run out of elements: */
	/* TODO: remember to copy back into the right locations in A! */
  #if 0
  while (r <= high){
    merged.push_back(A[r++]);
  }
  while ( l <= mid){
		merged.push_back(A[l++]);
	}
  #else
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
  #endif
  for (size_t i= low; i <= high; i++) {
  	A[i]=merged[i-low];
  }
}

/* sort A[low...high], inclusive. */
void mergeSort(vector<int>& A, size_t low, size_t high)
{
	#if 1
	/* base case: subarray has less than 2 elements: */
	if (low >= high) return;
	/* else, divide array in two equal-ish pieces,
	 * recursively sort each one, and then merge results. */
	size_t mid = (low+high) / 2;
	/* two subarrays are now low..mid and mid+1..high */
	mergeSort(A,low,mid);
	mergeSort(A,mid+1,high);
	merge(A,low,mid,high);
	/* TODO: convince yourself (ideally, with mathematical proof) that
	 * the subarrays we computed above will always be non-trivial.  That
	 * is, neither subarray will be the entire array A[low..high].
	 * (This is crucial to prevent infinite recursion!) */
	#else
	if (low < high) {
		size_t mid= (low+high)/2;
		mergeSort(A, low, mid);
		mergeSort(A,mid+1,high);
		merge (A, low, mid, high);
	}
	#endif
}

int main(void){
	#if 1
	vector<int> A= {2, 1, 4, 3, 9,6,7,5,8};
	#else
	vector <int> A;
	int temp;
	while (cin >> temp){
		A.push_back(temp);
	}
	#endif
	mergeSort(A,0,A.size()-1);
	for (size_t i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	return 0;
}

/* TODO: test this out.  A not very interesting test could look like:
 * $ echo {10..1} | ./test
 * */
/* TODO: trace this with gdb.  Build with `make -B debug`, run it
 * under gdb, step through the code, and remember the `bt` command
 * which shows you the current "stack" of function calls. */
