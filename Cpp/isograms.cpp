/*

An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

isIsogram "Dermatoglyphics" == true
isIsogram "moose" == false
isIsogram "aba" == false

*/

#include <algorithm>

bool is_isogram(std::string str) {
  std::transform(str.begin(), str.end(),str.begin(), ::toupper); //necessary for final submit
  if (str.empty()) {
    return true;
  }
  for (int j = 0; j < str.length()-1; j++) {
    for (int i = j; i < str.length()-1; i++) {
      if (str[j] == str[i+1]) {
        return false;
      }
    }
  }
  return true;
}
