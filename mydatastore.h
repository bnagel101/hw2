#include "datastore.h"
#include "user.h"
#include "product.h"
#include <vector>
#include "util.h"
#include <string>
#include <map>
//fix convert to lower 
//use maps for cart and users
//this is where you keep the map of all products to keywords
//uses functionality in search function that uses and or or

//has map data structure that pairs products to keywords
//includes a function addProduct()
//includes addUser()
//includes 
//includes a search() function that takes in a keyword returns a product

class MyDataStore : public DataStore {
	public:
		MyDataStore();
		~MyDataStore();
		//adds user
		void addUser(User* u);
		//adds product
		void addProduct(Product* p);
		//adds new database format to ostream
		void dump(std::ostream& ofile);
		//returns a vector of products that you get from all of the products
		//associated with the keywords in the terms vector, the type is the AND
		//or OR function (0 for AND) (1 for OR)
		std::vector<Product*> search(std::vector<std::string>& terms, int type);
		//takes username and product that they want to buy and adds it to a 
		//map of that user to a queue with their cart
		void addToCart(std::string uN, Product*);
		//goes through the cart designated to a user and removes the items one
		//by one as long as there is quantity of the product and enought money
		//in the users balance, if there isn't enough money or not enough quantity 
		//just keep going down the list
		void buyCart(std::string uN);
		//prints the products in the users cart; prints Invalid Username if needed
		void viewCart(std::string uN);
	protected:
		//map of products names to products
		std::map<std::string, Product*> nameProduct;
		//map of keywords to products
		std::map<std::string,  std::set<Product*>> keywordProduct;
		//map of usernames to users
		std::map<std::string, User*> username;
		//map of users to list of products
		std::map<User*, std::vector<Product*>> userCart;
};

void printSet(std::set<std::string> a);