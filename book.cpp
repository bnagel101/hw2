#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, string author) : Product(category, name, price, qty) {
	bIsbn = isbn;
	bAuthor = author;
}

set<string> lowerConv(set<string> a){
	set<string> newS;
	set<string>::iterator it = a.begin();
	while(it != a.end()){
		string data = *it;
		transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
		newS.insert(data);
	}
	return newS;
}

set<string> Book::keywords() {
	set<string> bKeys;
	bKeys.insert(category_);
	auto words = parseStringToWords(getName());
	setUnion(bKeys, words);
	words = parseStringToWords(bAuthor);
	setUnion(bKeys, words);
	bKeys.insert(bIsbn);
	bKeys = lowerConv(bKeys);
	return bKeys;
}

string Book::displayString() {
	ostringstream oss;
	//string display = category + "/n" + name + "/n" + price + "/n" + quantity + "/n" + bIsbn + "/n" + bAuthor + "/n";
	oss << category_ << endl;
	oss << getName() << endl;
	oss << getPrice() << endl;
	oss << getQty() << endl;
	oss << bIsbn << endl;
	oss << bAuthor << endl;
	return oss.str();
}

void Book::dump(ostream& os){
	cout << displayString();
}





