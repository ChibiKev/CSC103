#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
using std::string;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

int main() {
	#if 0
	/* print a frequency table for the strings we read
	 * from stdin. */
	string s; /* hold input */
	map<string,int> F; /* F[s] will store the count for s. */
	while (cin >> s) F[s]++;
	/* NOTE: it is crucial that integers are initialized
	 * to 0 here.  (Remember: integers that aren't part of a map
	 * are not initialized to 0 for you.) */
	for (map<string,int>::iterator i = F.begin(); i!=F.end(); i++) {
		cout << (*i).first << ":" << (*i).second << "\n";
		/* NOTE: *i actually has TWO parts: the key and the value.
		 * the key is stored in (*i).first, and the value is in
		 * (*i).second.  The picture in the notes might help you
		 * understand. */
		/* TODO: try to make sense out of the error message for this: */
		// cout << *i << endl;
	}
	/* to demonstrate that new values are initialized to 0: */
	// cout << "F[thing that wasn't in the map] == " << F["asdfasdfasdf"] << "\n";

#endif
/* TODO: re-write the above from scratch and make sure you understand
 * why it works. */
#if 0
	map <string,int> F;
	string s;
	while (cin >> s) {
		F[s]++;
	}
	for (map<string,int>::iterator i=F.begin();i!=F.end();i++){
		cout << (*i).first << ":" << (*i).second << endl;
	}
#endif
/* TODO: try to solve the same problem *WITHOUT* using maps!  Can you do
 * it with just vectors?  How about just sets?  */
#if 0
	vector <string> words;
	vector <string> uniquewords;
	vector <int> break_index;
	string s;
	while (cin >> s){
		words.push_back(s);
	}
	sort (words.begin(),words.end());
	for (size_t i=0; i!= words.size()-1;++i){
		if (words[i+1] != words[i]){
			uniquewords.push_back(words[i]);
			break_index.push_back(i);
		}
	}
	uniquewords.push_back(words[words.size()-1]);
	vector <int> wordcount(1,break_index[0]+1);
	for (size_t i=0; i!= break_index.size()-1;++i){
		wordcount.push_back(break_index[i+1] - break_index[i]);
	}
	wordcount.push_back(words.size()-1-break_index[break_index.size()-1]);
	cout << "the number of words in this text is: " << words.size() << endl;
	cout << "number of distinct words is: " << uniquewords.size() << endl;
	for (size_t i=0; i!= uniquewords.size();++i){
		cout << uniquewords[i] << " occurs " << wordcount[i] << " times " << endl;
	}
#else
	string input;
	vector <string> wordlist;
	cout << "enter the sentence to count words" << endl;
	while (cin >> input) wordlist.push_back(input);
	sort (wordlist.begin(), wordlist.end());
	int count=0;
	input=wordlist[0];
	for (size_t i=0; i < wordlist.size(); i++){
		if (wordlist[i] != input) {
			cout << input << "\t" << count << endl;
			count=0;
			input=wordlist[i];
	 	}
		count++;
	}
	cout << input << "\t" << count << endl;
#endif
/* TODO: if you managed to solve the above, estimate the number of
 * instructions your program will require to run on an input of n strings.
 * Then compare this with the solution using maps.  Note that M[s]++ takes
 * approximately log(n) steps if the map has n different strings. */

	return 0;
}