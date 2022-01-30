using namespace std;
 
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
 
class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    int start = 0, matchedchars = 0;
    unordered_map<char, int> freq;

    for (const char c : pattern)
        freq[c]++;

    for (int end = 0; end < str.size(); end++)
    {
        if (freq.find(str[end]) != freq.end())
        {
            freq[str[end]]--;
            if (freq[str[end]] == 0)
                matchedchars++;
        }

        if (matchedchars == freq.size())
            resultIndices.push_back(start);

        if (end >= pattern.size()-1)
        {
            if (freq.find(str[start]) != freq.end())
            {
                if (freq[str[start]] == 0)
                    matchedchars--;
                freq[str[start]]++;
                start++;
            }
        }
    }
    return resultIndices;
  }
};


int main(int argc, char *argv[]) {
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl << "---" << endl;
 
  result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl << "---" << endl;
}

