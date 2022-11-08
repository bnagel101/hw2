#include "movie.h"
#include <iostream>
#include <sstream>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) : Product(category, name, price, qty) {
	mGenre = genre;
	mRating = rating;
}


set<string> Movie::keywords() const{
	set<string> mKeys;
	mKeys.insert(category_);
	set<string> temp = parseStringToWords(getName());
	mKeys = setUnion(mKeys, temp);
	temp = parseStringToWords(mGenre);
	mKeys = setUnion(mKeys, temp);
	return mKeys;
}


string Movie::displayString() const{
	ostringstream oss;
	oss << getName() << "\n";
	oss << "Genre: " << mGenre << " Rating: " << mRating << "\n";
	oss << getPrice() << " " << getQty() << " left." << "\n";
	return oss.str();
}

void Movie::dump(ostream& os) const{
	Product::dump(os);
	os << mGenre << "\n" << mRating << "\n";
}