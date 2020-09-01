// Encryption and Decryption
// Max Beard

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void readFile(ifstream&, string&);
string substitute(string, char);
string* split(string);
string merge(string, string);
string reverse(string);

int main()
{
	ifstream inputFile("message.txt"),
		InputEvenFile("even.txt"),
		InputOddFile("odd.txt");
	ofstream OutputEvenFile("even.txt"),
		OutputOddFile("odd.txt");
	string original,
		sub,
		* arr,
		even,
		odd,
		merged,
		decrypted;

	// reading input from file
	readFile(inputFile, original);

	cout << "Encrypt then Decrypt by Max Beard\n" << endl;

	// printing out original string and substituting it
	cout << "Original: " << original << endl;
	sub = substitute(original, 'e');

	// splitting encrypted string into even and odd
	arr = split(sub);
	even = *(arr + 0);
	odd = *(arr + 1);

	// putting even and odd strings into files
	OutputEvenFile << even;
	OutputOddFile << odd;

	// displaying even and odd files
	cout << "file 1: ";
	InputEvenFile >> even;
	cout << even << endl;
	cout << "file 2: ";
	InputOddFile >> odd;
	cout << odd << endl;
	cout << "both files written\n" << endl;

	// reversing process
	cout << "Now reverse the process to decrypt\n" << endl;

	// merging and decrypting even and odd strings
	merged = merge(even, odd);
	decrypted = substitute(merged, 'd');

	// displaying original string against decrypted string
	cout << " original: " << original << endl;
	cout << "decrypted: " << decrypted << endl;

	// checking if strings match
	if (original == decrypted)
		cout << "Decryptecd and Original strings match!" << endl;
	else
		cout << "The strings do not match." << endl;

	delete[] arr;
	system("pause");
	return 0;
}

// reading from existing file
void readFile(ifstream& file, string& str)
{
	getline(file, str);
	file.close();
}

// substitutes each character with 
// a new ASCII character by adding
// a key to the original character
string substitute(string str, char type)
{
	// determining if encryption or decryption
	int key;
	if (type == 'e')
		key = 3;
	else if (type == 'd')
		key = -3;

	// making new string
	string newStr = "";
	for (char x : str) {
		newStr += (x + key);
	}
	return newStr;
}

// splits the string into 2 strings
// one with even positioned characters
// and one with odd positioned characters
// then puts each one into a file
string* split(string str)
{
	// reversing the string
	string reversedStr = reverse(str),
		evenStr = "",
		oddStr = "",
		* strArr = new string[2];

	// splitting string into even and odd strings
	int count = 0;
	for (char x : reversedStr) {
		if (count % 2 == 0)
			evenStr += x;
		else
			oddStr += x;
		count++;
	}

	// putting strings into array and returning it
	strArr[0] = evenStr;
	strArr[1] = oddStr;
	return strArr;
}


// merges the two even and odd strings
// so that they are interleaved into one string
string merge(string even, string odd)
{
	string newStr = "",
		revStr;
	int evenLen = even.length(),
		oddLen = odd.length(),
		maxLen;
	if (evenLen > oddLen)
		maxLen = oddLen;
	else
		maxLen = evenLen;

	// merging strings together
	int count = 0;
	while (count < maxLen) {
		newStr += even.at(count);
		newStr += odd.at(count);
		count++;
	}
	if (evenLen == oddLen)
		maxLen += 1;
	if (maxLen == oddLen)
		newStr += even.at(count);

	// reversing string back and returning it
	revStr = reverse(newStr);
	return revStr;
}

// reverses the string
string reverse(string str)
{
	stack<char, vector<char>> stack;
	string newStr = "";

	// putting strings into stack
	for (char x : str) {
		stack.push(x);
	}

	// reverse string by popping stack
	while (!stack.empty()) {
		newStr += stack.top();
		stack.pop();
	}

	// returning reversed string
	return newStr;
}