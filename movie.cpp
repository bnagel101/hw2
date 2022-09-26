#include "movie.h"
#include <iostream>
#include <sstream>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) : Product(category, name, price, qty) {
	mGenre = genre;
	mRating = rating;
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

set<string> Movie::keywords() const{
	set<string> mKeys;
	mKeys.insert(category_);
	auto words = parseStringToWords(getName());
	setUnion(mKeys, words);
	words = parseStringToWords(mGenre);
	setUnion(mKeys, words);
	mKeys = lowerConv(mKeys);
	return mKeys;
}


string Movie::displayString() const{
	ostringstream oss;
	oss << category_ << endl;
	oss << getName() << endl;
	oss << getPrice() << endl;
	oss << getQty() << endl;
	oss << mGenre << endl;
	oss << mRating << endl;
	return oss.str();
}

void Movie::dump(ostream& os){
	cout << displayString();
}