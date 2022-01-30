using namespace std;
 
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
 
class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char, int> count;
    int start = 0, maxrepeatingcharlen = 0;
    for (int end = 0; end < str.size(); end++)
    {
        count[str[end]]++;

        maxrepeatingcharlen = max(maxrepeatingcharlen, count[str[end]]);

        if ((end - start + 1 - maxrepeatingcharlen) > k)
        {
            count[str[start]]--;
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << CharacterReplacement::findLength("aaaabccbaaaaaaa", 2) << endl;
  cout << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << CharacterReplacement::findLength("abccde", 1) << endl;
}

