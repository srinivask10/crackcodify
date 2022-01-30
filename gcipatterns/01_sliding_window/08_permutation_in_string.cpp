using namespace std;
 
#include <iostream>
#include <string>
#include <unordered_map>
 
class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
      int start = 0, matchchars = 0;

      unordered_map<char, int> freq;
      for (const char &c : pattern)
          freq[c]++;

      for (int end = 0; end < str.size(); end++)
      {
          if (freq.find(str[end]) != freq.end())
          {
              freq[str[end]]--;
              if (freq[str[end]] == 0)
                  matchchars++;
          }

          if (matchchars == freq.size())
            return true;

          if (end >= pattern.size()-1)
          {
              if (freq.find(str[start]) != freq.end())
              {
                  if (freq[str[start]] == 0)
                    matchchars--;
                  freq[str[start]]++;
              }
              start++;
          }
      }

    return false;
  }
};
 
int main(int argc, char *argv[]) {
  cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}

