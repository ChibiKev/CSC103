/* implementation of home brew vector. */
#include "vector2.h"
#include <cassert>

/* TODO: read through this (including the comments), looking back at
 * chapter 9 as needed.  Ask questions if something is confusing.  */

vector2::vector2(size_t initCapacity) {
	/* set vector to be empty, with initial capacity of initCapacity */
	size = 0;
	capacity = initCapacity;
	data = new int[capacity];
}

vector2::vector2(const vector2& V)
{
	/* Goal: make *this a copy of V. */
	size = V.size; /* copy size */
	capacity = V.capacity; /* copy capacity */
	/* how to copy data? */
	//data = V.data;
	/* NO!  Above will end in disaster. TODO: make sure you understand why.
	 * Imagine what will happen if a vector were passed *by value* to a
	 * function.  Draw pictures, and keep in mind what the destructor does.
	 * Anyway, we need to make a separate copy of V.data: */
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = V.data[i];
	}
}

vector2::~vector2() {
	/* free memory resources */
	delete [] data;
	/* NOTE: the brackets should be used when deleting arrays. */
}

/* assignment operator.  there's a neat trick you can do to re-use the
 * copy constructor to do most of the work.  TODO: see if you can
 * explain what is going on below / why it works.  We'll go through it
 * in detail next class. */
vector2& vector2::operator=(vector2 V)
{
	int* tmp = data;
	data = V.data;
	V.data = tmp;
	size = V.size;
	capacity = V.capacity;
	return (*this);
}

/* TODO: re-write the assignment operator using the following prototype: */
// vector2& operator=(const vector2& V);
/* the const by reference seems more plausible, but it will complicate
 * the implementation a good bit.  NOTE: you will have to modify the
 * header as well. */

/* push back: */
void vector2::push_back(int x) {
	/* TODO: try to write this.  See the notes from lecture. */
	if (size==capacity){
		capacity*=2;
		int* newdata= new int [capacity];
		for (size_t i=0; i < size; i++){
			newdata[i]=data[i];
		}
		delete [] data;
		data= newdata;
	}
	data[size++] = x;
}

/* this should return the item we remove */
int vector2::pop_back() {
	/* TODO: try to write this. */
	assert(size > 0);
	return data[--size];
}
