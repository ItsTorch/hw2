#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "util.h"
#include <string>
#include <vector>
#include <set>
#include <map>

class MyDataStore : public DataStore {
  public:
    MyDataStore();
    ~MyDataStore();
    
    // add product to data store
    void addProduct(Product* p);
    
    // add user to data store
    void addUser(User* u);

    // search products with keywords matching products
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    // reproduce database file from products and user values
    void dump(std::ostream& ofile);

    // menu options for user to choose
    void addToCart(const std::string& username, Product* p);
    void viewCart(const std::string& username) const;
    void buyCart(const std::string& username);

    // helps check if user exists
    bool userExists(const std::string& username) const;

  private:
    std::vector<Product*> products_;
    std::vector<Product*> lastSearchResults_;
    std::vector<User*> users_;
    std::map<std::string, std::set<Product*>> keywordMap_;
    std::map<std::string, std::vector<Product*>> carts_;
    std::map<std::string, User*> userMap_;
};
#endif