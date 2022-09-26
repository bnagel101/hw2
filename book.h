#include "product.h"


class Book : public Product {
	public:
		Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os);
	protected:
		std::string bIsbn;
		std::string bAuthor;
};


