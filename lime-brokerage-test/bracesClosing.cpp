/********************************************************************************************************************************
 * THIS IS NOT FINISHED
 *
 * Determines whether a string contains self-closing braces. 
 * 
 * Example input: {[{}]}, [[{]}[}
 * Example output: YES, NO
 ********************************************************************************************************************************/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector < string > Braces(vector < string > values);

int main(int argc, char *argv[]) {

  vector <string> stuff;
  vector <string> result;
  stuff.push_back("{()}"); //Should say yes
  stuff.push_back("{[()]}"); //Should say yes
  stuff.push_back("{(})]}]{}]{"); //Should say no
  stuff.push_back("}}]{()}"); //Should say no
  stuff.push_back("()"); //Should say yes
  stuff.push_back("{({[{}]})}"); //Should say yes
  stuff.push_back("{[{()}"); //Should say no
  stuff.push_back("}]{()}"); //Should say no
  stuff.push_back("{()}{["); //Should say no
  stuff.push_back("{()}}]"); //Should say no

  result = Braces(stuff);

  for(std::vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << *it;
    cout << endl;
  }

  return 0;
}

vector < string > Braces(vector < string > values) {

  vector < string > result;
  string current;
  vector < char > lastChars;
  bool isFine;

  for(std::vector<string>::iterator it = values.begin(); it != values.end(); ++it) {
    isFine = true;
    current = *it;
    for( int i=0; i < current.length(); i++) {      
      if (current[i] == '(') {
        lastChars.push_back('(');
      }
      else if (current[i] == '[') {
        lastChars.push_back('[');
      }
      else if (current[i] == '{') {
        lastChars.push_back('{');
      }
      else if (current[i] == ')') {
        if('(' == lastChars.back()) {
          lastChars.pop_back();
        } else {
          isFine=false;
          break;
        }
      }
      else if (current[i] == ']') {
        if('[' == lastChars.back()) {
          lastChars.pop_back();
        } else {
          isFine=false;
          break;
        }
      }
      else if (current[i] == '}') {
        if('{' == lastChars.back()) {
          lastChars.pop_back();
        } else {
          isFine=false;
          break;
        }
      }
    }
    if(!isFine) {
      result.push_back("NO");
      lastChars.clear();
      continue;
    }
      
    (lastChars.empty()) ? (result.push_back("YES")) : (result.push_back("NO"));
    lastChars.clear();
  }
  return result;

}
