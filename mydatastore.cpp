#include "mydatastore.h"
#include <iostream>
#include <sstream>

using namespace std;

MyDataStore::MyDataStore() {
	
}
//adds user in user cart map, new user have empty vector of products
void MyDataStore::addUser(User* u){
	string userN = convToLower(u->getName());
	username[userN] = u;

	// username.insert(make_pair(userN, U));
	vector<Product*> temp;
	userCart[u] = temp;
}

//adds product to the string product map
//gets list of keywords from product and adds them into the keywordProduct map
//if a keyword is already in the map it adds the product into the set already made 
//if a keyword is not in the map is adds it to the map and creates a new set and adds the product to that set
void MyDataStore::addProduct(Product* p){
	//nameProduct.insert({p->getName(), p});
	string productN = convToLower(p->getName());
	nameProduct[productN] = p;
	set<string> keys = p->keywords();
	set<string>::iterator it = keys.begin();
	while(it != keys.end()){		
		if(keywordProduct.find(*it) != keywordProduct.end()){
			keywordProduct[*it].insert(p);
		}else{
			set<Product*> temp;
			temp.insert(p);
			keywordProduct[*it] = temp;
		}
		++it;
	}

}

//tester function to print a set
void printSet(set<string> a){
	set<string>::iterator itt = a.begin();
	for(; itt != a.end(); ++itt){
		cout << *itt << endl;
	}
}
//goes through the cart designated to a user and removes the items one
		//by one as long as there is quantity of the product and enought money
		//in the users balance, if there isn't enough money or not enough quantity 
		//just keep going down the list
//instead of removing products, it just adds products that shouldnt be removed into a new vector and replaces the vector
void MyDataStore::buyCart(string uN){
	if(username.find(uN) != username.end()){
		User* u = username[uN];
		vector<Product*> a = userCart[u];
		vector<Product*> temp;
		for(int i = 0; i < (int)a.size(); i++){
			if((u->getBalance() - (a[i])->getPrice() >= 0) && ((a[i])->getQty() > 0)){
				(a[i])->subtractQty(1);
				u->deductAmount((a[i])->getPrice());
			}else{
				temp.push_back(a[i]);
			}
		}
		userCart[u] = temp;
	}else{
		cout << "Invalid Request";
	}
}

//takes username and product that they want to buy and adds it to a 
		//map of that user to a queue with their cart
		//need to print invalid request if stuff isn't right
void MyDataStore::addToCart(string uN, Product* product){
	if(username.find(uN) != username.end()){
		User* u = username[uN];
		userCart[u].insert(userCart[u].end(), product);
	}else{
		cout << "Invalid Request";
	}
	
}
//returns a vector of products that you get from all of the products
		//associated with the keywords in the terms vector, the type is the AND
		//or OR function (0 for AND) (1 for OR)
vector<Product*> MyDataStore::search(vector<string>& terms, int type){
	
	set<Product*> results1;
	if(terms.size() > 0){
		results1 = keywordProduct[terms[0]];
	}
	for(int i = 1; i < (int)terms.size(); i++){
		if(type == 0){
			results1 = setIntersection(results1, keywordProduct[terms[i]]);
			
		}else{
			results1 = setUnion(results1, keywordProduct[terms[i]]);
		}
	}

	vector<Product*> results (results1.begin(), results1.end());
	return results;
}
//prints out everything in users cart
void MyDataStore::viewCart(string uN){
	if(username.find(uN) != username.end()){
		User* u = username[uN];
		vector<Product*> a = userCart[u];
		cout << "User: " << uN << endl;
		for(int i = 0; i < (int)a.size(); i++){
			cout << "Index: " << i+1 << endl;
			cout << a[i]->displayString();
		}
	}else{
		cout << "Invalid Request";
	}
}

//adds the new database format to the ostream file, first adds products and then users
void MyDataStore::dump(std::ostream& ofile){
	ofile << "<product>" << endl;
	//std::map<std::string, Product*> nameProduct;
	for(pair<string, Product*> i: nameProduct){
		(i.second)->dump(ofile);
	}
	ofile << "<product>" << endl;
	ofile << "<users>" << endl;
	for(pair<string, User*> i: username){
		(i.second)->dump(ofile);
	}
	ofile << "<users>" << endl;
}

//destructor
MyDataStore::~MyDataStore(){

}


