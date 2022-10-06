#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, string author) : Product(category, name, price, qty) {
	bIsbn = isbn;
	bAuthor = author;
}

//creates set of strings to fill with keywords, creates another set of strings
// for name and product specific strings in order to call the parseStringToWords
// function on it, then uses the set union function to join the two sets
set<string> Book::keywords() const{
	set<string> bKeys;
	bKeys.insert(category_);
	set<string> temp = parseStringToWords(getName());
	bKeys = setUnion(temp, bKeys);
	temp = parseStringToWords(bAuthor);
	bKeys = setUnion(bKeys, temp);
	bKeys.insert(bIsbn);
	return bKeys;
}

//adds all product terms and product specific terms in order specified and returns the ostringstream
string Book::displayString() const{
	ostringstream oss;
	//string display = category + "/n" + name + "/n" + price + "/n" + quantity + "/n" + bIsbn + "/n" + bAuthor + "/n";
	oss << getName() << endl;
	oss << "Author: " << bAuthor << " ISBN: " << bIsbn << endl;
	oss << getPrice() << " " << getQty() << " left." << endl;
	return oss.str();
}

//edits the ostream by using the product dump function and then adds product specific terms
void Book::dump(ostream& os){
	Product::dump(os);
	os << bIsbn << endl << bAuthor << endl;
}





