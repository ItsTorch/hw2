#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class Book : public Product {
  public:
    Book(const std::string name, double price, int qty,
    const std::string isbn, const std::string author);

    // derived from product class
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  private:
    // specific to book products
    std::string isbn_;
    std::string author_;
};
#endif