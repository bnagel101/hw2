#include "clothing.h"
#include <iostream>
#include <sstream>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) : Product(category, name, price, qty) {
	cSize = size;
	cBrand = brand;
}


set<string> Clothing::keywords() const{
	set<string> cKeys;
	cKeys.insert(category_);
	set<string> temp = parseStringToWords(getName());
	cKeys = setUnion(cKeys, temp);
	temp = parseStringToWords(cSize);
	cKeys = setUnion(cKeys, temp);
	temp = parseStringToWords(cBrand);
	cKeys = setUnion(cKeys, temp);
	return cKeys;
}


string Clothing::displayString() const{
	ostringstream oss;
	oss << getName() << endl;
	oss << "Size: " << cSize << " Brand: " << cBrand << endl;
	oss << getPrice() << " " << getQty() << " left." << endl;
	return oss.str();
}
	
void Clothing::dump(ostream& os){
	Product::dump(os);
	os << cSize << endl << cBrand << endl;
}
