#include "clothing.h"
#include "util.h"
#include <sstream>
#include <set>

Clothing::Clothing(const std::string name, double price, int qty,
const std::string size, const std::string brand)
  : Product("clothing", name, price, qty), size_(size), brand_(brand)

  // all details of clothing product
{

}

std::set<std::string> Clothing::keywords() const {

  std::set<std::string> keywords;

  // parse clothing name, size, and brand
  std::set<std::string> nameKeywords = parseStringToWords(name_);
  std::set<std::string> sizeKeywords = parseStringToWords(size_);
  std::set<std::string> brandKeywords = parseStringToWords(brand_);

  // added keywords of name, genre, and rating of movie
  keywords.insert(nameKeywords.begin(), nameKeywords.end());
  keywords.insert(sizeKeywords.begin(), sizeKeywords.end());
  keywords.insert(brandKeywords.begin(), brandKeywords.end());

  return keywords;
}

std::string Clothing::displayString() const {

  std::stringstream display;

  // displays clothing product
  display << name_ << std::endl;
  display << "Size: " << size_ << " Brand: " << brand_ << std::endl;
  display << price_ << " " << qty_ << " " << "left." <<std::endl;

  return display.str();
}

void Clothing::dump(std::ostream& os) const {

  // outputs product details to database
  os << "clothing" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << size_ << std::endl;
  os << brand_ << std::endl;
}