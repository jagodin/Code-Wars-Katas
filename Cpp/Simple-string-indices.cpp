/*

In this Kata, you will be given a string with brackets and an index of an opening bracket and your task will be to return the index of the matching closing bracket. Both the input and returned index are 0-based except in Fortran where it is 1-based. An opening brace will always have a closing brace. Return -1 if there is no answer (Haskell return Nothing, Fortran: return 0)

Examples
solve("((1)23(45))(aB)", 0) = 10 // the opening brace at index 0 matches the closing brace at index 10
solve("((1)23(45))(aB)", 1) = 3 
solve("((1)23(45))(aB)", 2) = -1 // there is no opening bracket at index 2, so return -1
solve("((1)23(45))(aB)", 6) = 9
solve("((1)23(45))(aB)", 11) = 14
solve("((>)|?(*'))(yZ)", 11) = 14
Input will consist of letters, numbers and special characters, but no spaces. The only brackets will be ( and ).

*/

#include <string>
#include <map>

int solve(std::string str, int index){
  std::map<std::string, int> bracketMap;
  
  bracketMap["("] = 0;
  bracketMap[")"] = 0;
  
  if (char(str[index]) != '(') {
    return -1;
  }  else {
    for (int i = index; i<str.size(); i++) {
      if (char(str[i]) == '(') bracketMap["("]++;
      if (char(str[i]) == ')' && i) bracketMap[")"]++;
      
      if (bracketMap["("] == bracketMap[")"]) return i;
    }
  }
  return -1;
}