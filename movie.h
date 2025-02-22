#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie : public Product {
  public:
    Movie(const std::string name, double price, int qty, std::string genre, std::string rating);

    // derived from product class
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  private:
    //specific to movie products
    std::string genre_;
    std::string rating_;
};
#endif