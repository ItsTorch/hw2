#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // set of all intersections
  std::set<T> intersectSet;

  // iterate through both set s1 and set s2
  typename std::set<T>::iterator it1 = s1.begin();
  typename std::set<T>::iterator it2 = s2.begin();

  // finds intersection between two sets, what both sets have in common
  while ((it1 != s1.end()) && (it2 != s2.end())) {
    if (*it1 == *it2) {
      intersectSet.insert(*it1);
      it1++;
      it2++;
    }
    else if (*it1 < *it2) {
      it1++;
    }
    else {
      it2++;
    }
  }

  return intersectSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  // set of unions
  std::set<T> unionSet;

  // iterate through both set s1 and set 2
  typename std::set<T>::iterator it1 = s1.begin();
  typename std::set<T>::iterator it2 = s2.begin();

  // combines both sets together into one set, the union of sets
  while ((it1 != s1.end()) && (it2 != s2.end())) {
    if (*it1 == *it2) {
      unionSet.insert(*it1);
      it1++;
      it2++;
    }
    else if (*it1 < *it2) {
      unionSet.insert(*it1);
      it1++;
    }
    else {
      unionSet.insert(*it2);
      it2++;
    }
  }

  // if either set hasn't been fully traversed yet, do so and add them
  while (it1 != s1.end()) {
    unionSet.insert(*it1);
    it1++;
  }

  while (it2 != s2.end()) {
    unionSet.insert(*it2);
    it2++;
  }

  return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
