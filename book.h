#include "product.h"


class Book : public Product {
	public:
		Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
		//function returns keywords
		std::set<std::string> keywords() const;
		//returns string of info on book
		std::string displayString() const;
		//adds database formate to ostream
		void dump(std::ostream& os);
		~Book()=default;
	protected:
		std::string bIsbn;
		std::string bAuthor;
};


