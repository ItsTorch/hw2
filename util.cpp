#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
  // create set of individual keywords
  std::set<std::string> keywords;

  // one keyword to be put into set
  std::string word;

  // taking raw words, turn them into keywords, and then insert into set
  for (size_t i = 0; i <= rawWords.size(); i++) {
    
    // if else, space triggers last word to be inserted
    char c = (i < rawWords.size()) ? rawWords[i] : ' ';
    
    if (isspace(c) || ispunct(c)) {
        if (word.length() >= 2) {
            keywords.insert(convToLower(word));
        }
        word.clear();
    }
    else {
        word += c;
    }
  }
  return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
