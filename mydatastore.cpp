#include "mydatastore.h"
#include "util.h"
#include "product.h"
#include <iostream>

MyDataStore::MyDataStore() {
  // constructor
}

MyDataStore::~MyDataStore() {
  // destructor, remove products and users
  for (size_t i = 0; i < products_.size(); i++) {
    delete products_[i];
  }
  for (size_t i = 0; i < users_.size(); i++) {
    delete users_[i];
  }
}

void MyDataStore::addProduct(Product* p) {
  
  // adds to products list
  products_.push_back(p);
  
  // add to set as keywords
  std::set<std::string> keywords = p->keywords();

  // put keywords into map
  for (std::set<std::string>::iterator it = keywords.begin(); it != keywords.end(); it++) {
    keywordMap_[convToLower(*it)].insert(p);
  }
}

void MyDataStore::addUser(User* u) {
  // adds user and apply products for them
  std::string lowerUsername = convToLower(u->getName());
  users_.push_back(u);
  carts_[lowerUsername] = std::vector<Product*>();
  userMap_[lowerUsername] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::set<Product*> searchResult;
  
  if (terms.size() == 0) {
    return std::vector<Product*>();
  }
  
  // initialize search with nonempty term
  size_t idx = 0;
  while ((idx < terms.size()) && terms[idx].empty()) {
    idx++;
  }

  // no valid search terms
  if (idx == terms.size()) {
    return std::vector<Product*>();
  }

  std::set<Product*> searchSet = keywordMap_[convToLower(terms[idx])];

  // search remain words
  for (size_t i = idx + 1; i < terms.size(); i++) {
    if (terms[i].empty()) {
      continue;
    }

    std::set<Product*> termSet = keywordMap_[convToLower(terms[i])];
    if (type == 0) {
      searchSet = setIntersection(searchSet, termSet);
    }
    else {
      searchSet = setUnion(searchSet, termSet);
    }
  }
  return std::vector<Product*>(searchSet.begin(), searchSet.end());
}

void MyDataStore::dump(std::ostream& ofile) {
  // puts all info into database in format
  ofile << "<products>" << std::endl;
  for (size_t i = 0; i < products_.size(); i++) {
    products_[i]->dump(ofile);
  }
  ofile << "</products>" << std::endl;
  ofile << "<users>" << std::endl;
  for (size_t i = 0; i < users_.size(); i++) {
    users_[i]->dump(ofile);
  }
  ofile << "</users>" << std::endl;
}

void MyDataStore::addToCart(const std::string& username, Product* p) {
  // adds product to the user's cart
  std::string lowerUsername = convToLower(username);
  if (carts_.find(lowerUsername) !=carts_.end()) {
    carts_[lowerUsername].push_back(p);
  }
}

void MyDataStore::viewCart(const std::string& username) const {
  // allows user to check all products in their cart
  std::string lowerUsername = convToLower(username);
  std::map<std::string, std::vector<Product*>>::const_iterator it = carts_.find(lowerUsername);
  
  if (it != carts_.end()) {
    for (size_t i = 0; i < it->second.size(); i++) {
      std::cout <<"Item " << i + 1 << std::endl; 
      std::cout << it->second[i]->displayString() << std::endl;
    }
  }
  else {
    std::cout << "Invalid username" << std::endl;
  }
}

void MyDataStore::buyCart(const std::string& username) {
  std::string lowerUsername = convToLower(username);
  std::map<std::string, std::vector<Product*>>::iterator it = carts_.find(lowerUsername);
  
  if (it != carts_.end()) {
    std::vector<Product*>& cart = it->second;
    User* user = userMap_[lowerUsername];
    std::vector<Product*> leftInCart;
  
    // checks product costs in cart and credit user has to determine if they can purchase
    for (size_t i = 0; i < cart.size(); i++) {
      Product* product = cart[i];
      if ((product->getQty() > 0) && (user->getBalance() >= product->getPrice())) {
        product->subtractQty(1);
        user->deductAmount(product->getPrice());
      }
      else {
        leftInCart.push_back(product);
      }
    }
    cart.swap(leftInCart);
  }
  else {
    std::cout << "Invalid username" << std::endl;
  }
}

bool MyDataStore::userExists(const std::string& username) const {
  std::string lowerUsername = convToLower(username);

  // checks if user exists
  return userMap_.find(lowerUsername) != userMap_.end();
}