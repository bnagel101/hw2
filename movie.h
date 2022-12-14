#include "product.h"

class Movie : public Product {
	public:
		Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;
		~Movie()=default;
	protected:
		std::string mGenre;
		std::string mRating;
};

