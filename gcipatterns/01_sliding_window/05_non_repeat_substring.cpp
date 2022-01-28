using namespace std;
 
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
 
class NoRepeatSubstring {
 public:
    static int findLength(const string& str) {
        int maxLength = 0;
        unordered_map<char, int> indexmap;

        int start = 0;
        for (int end = 0; end < str.size(); end++)
        {
            if (indexmap.find(str[end]) != indexmap.end())
                start = max(start, indexmap[str[end]] + 1);
            indexmap[str[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}

