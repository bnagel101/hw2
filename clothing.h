#include "product.h"

class Clothing : public Product {
	public:
		Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os);
		~Clothing()=default;
	protected:
		std::string cSize;
		std::string cBrand;
};

