#include "movie.h"
#include "util.h"
#include <sstream>
#include <set>

Movie::Movie(const std::string name, double price, int qty,
const std::string genre, const std::string rating)
  : Product("movie", name, price, qty), genre_(genre), rating_(rating)

  // all details of movie product
{

}

std::set<std::string> Movie::keywords() const {

  std::set<std::string> keywords;

  // parse movie name, genre, and rating
  std::set<std::string> nameKeywords = parseStringToWords(name_);
  std::set<std::string> genreKeywords = parseStringToWords(genre_);
  std::set<std::string> ratingKeywords = parseStringToWords(rating_);

  // added keywords of name, genre, and rating of movie
  keywords.insert(nameKeywords.begin(), nameKeywords.end());
  keywords.insert(genreKeywords.begin(), genreKeywords.end());
  keywords.insert(ratingKeywords.begin(), ratingKeywords.end());

  return keywords;
}

std::string Movie::displayString() const {

  std::stringstream display;

  // displays movie product
  display << name_ << std::endl;
  display << "Genre: " << genre_ << " Rating: " << rating_ << std::endl;
  display << price_ << " " << qty_ << " left." << std::endl;

  return display.str();
}

void Movie::dump(std::ostream& os) const {

  // outputs product details to database
  os << "movie" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << genre_ << std::endl;
  os << rating_ << std::endl;
}