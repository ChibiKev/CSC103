#include "vector2.h"
#include <cassert>
#include <algorithm>
using std::swap;

/* NOTE: if we define  */
// #define NDEBUG 1
/* then the assert() will disappear from the compiler input */

vector2::vector2(size_t initCapacity){
	/* set vector to be empty, with initial capacity of initCapacity */
	size = 0;
	capacity = initCapacity;
	data = new int[capacity];
}

/* example of calling copy constructor:
 * vector2 V;
 * ... stuff ...
 * now make W a copy of V:
 * vector2 W(V);
 * NOTE: W will be a synonym for *this when the C.C. is called.
 * */
vector2::vector2(const vector2& V){
	/* Goal: make *this a copy of V. */
	size = V.size; /* copy size */
	capacity = V.capacity; /* copy capacity */
	/* how to copy data? */
	data = V.data;
	return;
	/* NO!  Above will end in disaster. TODO: make sure you understand why.
	 * Try out the above version and see what errors you get when running
	 * the main program.  Comment / remove it and use the following once
	 * you've satisfied your appetite for destruction. */
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		(*this).data[i] = V.data[i];
		/* NOTE: there is a shorthand for (*pointer).member which is
		 * pointer->member (then you don't have to type as many parens) */
	}
}

vector2::~vector2() {
	/* free memory resources */
	delete [] data;
	/* NOTE: the brackets should be used when deleting arrays. */
}

/* here's a "classical" assignment operator */
/* NOTE: calling V = W; leads to the function call V.operator=(W); */
#if 0
vector2& vector2::operator=(const vector2& RHS) {
	/* goals: make (*this) a copy of V.  We'll need to
	 * delete the data of the LHS, make a new allocation
	 * of the right size, and then copy all the data. */

	/* first, have to check for "self-assignment".  That is,
	 * what if someone does V=V somehow? */
	if (this == &RHS) /* corresponds to V=V */
		return *this;
	/* clean up LHS memory: */
	delete[] data;
	/* now follow copy constructor more or less: */
	size = RHS.size;
	capacity = RHS.capacity;
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = RHS.data[i];
	}
	return *this;
}
#endif

/* fancy assignment operator.  uses neat trick to re-use
 * the copy constructor to do most of the work.
 * (Btw, assignment operator is used when you make
 * an assignment between vectors, e.g.
 * vector V,W;
 * ...
 * V = W; //<-- calls assignment operator.
 * */
vector2& vector2::operator=(vector2 V){
	/* swap data pointers of *this and V: */
	swap(data,V.data);
	/* copy size and capacity from V */
	size = V.size;
	capacity = V.capacity;
	return (*this);
}

/* TODO: make sure you understand how the both versions of the
 * assignment operator are actually equivalent. */

int& vector2::operator[](size_t i) {
	/* TODO: write this.  Use the assert function like we did for pop_back */
	/* NOTE: we are returning by reference!  Why?? */
}

/* TODO: in case you didn't do these last time, erase push and pop and
 * write them from scratch. */
void vector2::push_back(int x) {
	/* make sure we have enough space: */
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		for (size_t i = 0; i < size; i++) {
			newArray[i] = data[i];
		}
		delete [] data;
		data = newArray;
	}
	data[size++] = x;
	/* TODO: try to write this from scratch.  At a minimum, refer back to
	 * the diagram from the lecture and make sure the pictures match up
	 * with the code. */
}
int vector2::pop_back() {
	assert(size);
	return data[--size];
}
