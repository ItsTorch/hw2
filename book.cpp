#include "book.h"
#include "util.h"
#include <sstream>
#include <set>

Book::Book(const std::string name, double price, int qty, 
const std::string isbn, const std::string author)
  : Product("book", name, price, qty), isbn_(isbn), author_(author)

  // all details of book product
{

}

std::set<std::string> Book::keywords() const {
  
  std::set<std::string> keywords;

  // parse book name and author, but not ISBN
  std::set<std::string> nameKeywords = parseStringToWords(name_);
  std::set<std::string> authorKeywords = parseStringToWords(author_);

  // added keywords of title, isbn, and author of book
  keywords.insert(nameKeywords.begin(), nameKeywords.end());
  keywords.insert(convToLower(isbn_));
  keywords.insert(authorKeywords.begin(), authorKeywords.end());

  return keywords;
}

std::string Book::displayString() const {
  
  std::stringstream display;
  
  // displays book product
  display << name_ << std::endl;
  display << "Author: " << author_ << " ISBN: " << isbn_ << std::endl;
  display << price_ << " " << qty_ << " " << "left." << std::endl;

  return display.str();
}

void Book::dump(std::ostream& os) const {

  // outputs product details to database
  os << "book" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << isbn_ << std::endl;
  os << author_ << std::endl;
}