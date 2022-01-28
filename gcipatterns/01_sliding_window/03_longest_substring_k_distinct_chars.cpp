using namespace std;
 
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
 
class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char, int> count;

    int start = 0;
    for (int end = 0; end < str.size(); end++)
    {
        count[str[end]]++;
        while (count.size() > k)
        {
            count[str[start]]--;
            if (count[str[start]] == 0)
                count.erase(str[start]);
            start++;
        }
        maxLength = max(maxLength, end - (start - 1));
    }

    return maxLength;
  }
};


int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}

