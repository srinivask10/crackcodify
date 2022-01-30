using namespace std;
 
#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {

      unordered_map<char, int> freq;
      int matchedchars = 0, start = 0, minlength = str.size() + 1, substridx = 0;

      for (const char c : pattern)
        freq[c]++;

      for (int end = 0; end < str.size(); end++)
      {
          if (freq.find(str[end]) != freq.end())
          {
              freq[str[end]]--;
              if (freq[str[end]] >= 0)
                matchedchars++;
          }

          while (matchedchars == pattern.size())
          {
              if (minlength > end - start + 1)
              {
                  minlength = end - start + 1;
                  substridx = start;  
              }

              if (freq.find(str[start]) != freq.end())
              {
                  if (freq[str[start]] == 0)
                    matchedchars--;
                  freq[str[start]]++;
              }
              start++;
          }
      }
      return (minlength > str.size()) ? "" : str.substr(substridx, minlength);
  }
};

int main(int argc, char *argv[]) {
  cout << MinimumWindowSubstring::findSubstring("aabdec", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("abdabca", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("adcad", "abc") << endl;
}

