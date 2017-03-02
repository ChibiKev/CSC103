/* strings.cpp
 * More examples working with strings...
 * */
#include <iostream>
using std::cin;
using std::cout; 
using std::endl;
#include <string>
using std::string;

/* TODO:  write a function that takes a string and a character
 * and returns the number of occurences of the character in the string.
 * We did this in class, but it is a good self-test.  Try to write it
 * from scratch without looking.
 * */
size_t countChars(const string& s, char c)
{
	return 0;
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

/* TODO: write a function that takes two strings and returns an integer value
 * indicating whether or not the first was a substring of the second.  Remember
 * that the return value should be the index at which the string was found, or
 * -1 to indicate that the string was not found.
 * */
int isSubstring(const string& s1, const string& s2) {
	return -1;
}

/* NOTE: there is a built-in string function for this (find(str,pos)).
 * TODO: try it out (but don't use it to solve the above, of course!).
 * */

/* TODO: write a function that takes a string by reference and reverses it.
 * We outlined this in lecture.  Make sure you can do it on your own.
 * */

int main() {
	/* TODO: write test code for all of the functions you wrote above */
	return 0;
}
