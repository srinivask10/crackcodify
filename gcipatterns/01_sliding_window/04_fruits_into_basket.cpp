using namespace std;
 
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    unordered_map<char, int> count;
    int start = 0;

    for (int end = 0; end < arr.size(); end++)
    {
        count[arr[end]]++;
        while (count.size() > 2)
        {
            count[arr[start]]--;
            if (count[arr[start]] == 0)
                count.erase(arr[start]);
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}

