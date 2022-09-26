#include "clothing.h"
#include <iostream>
#include <sstream>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) : Product(category, name, price, qty) {
	cSize = size;
	cBrand = brand;
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

set<string> Clothing::keywords() const{
	set<string> cKeys;
	cKeys.insert(category_);
	auto words = parseStringToWords(getName());
	setUnion(cKeys, words);
	words = parseStringToWords(cSize);
	setUnion(cKeys, words);
	words = parseStringToWords(cBrand);
	setUnion(cKeys, words);
	cKeys = lowerConv(cKeys);
	return cKeys;
}


string Clothing::displayString() const{
	ostringstream oss;
	//string display = category + "/n" + name + "/n" + price + "/n" + quantity + "/n" + bIsbn + "/n" + bAuthor + "/n";
	oss << category_ << endl;
	oss << getName() << endl;
	oss << getPrice() << endl;
	oss << getQty() << endl;
	oss << cSize << endl;
	oss << cBrand << endl;
	return oss.str();
}

void Clothing::dump(ostream& os){
	cout << displayString();
}
