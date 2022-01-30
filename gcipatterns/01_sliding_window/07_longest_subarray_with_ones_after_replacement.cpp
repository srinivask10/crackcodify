using namespace std;
 
#include <iostream>
#include <vector>
#include <algorithm>
 
class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    
    int maxones = 0, start = 0;
    for (int end = 0; end < arr.size(); end++)
    {
        if (arr[end] == 1)
            maxones++;

        if (end - start + 1 - maxones > k)
        {
            if (arr[start] == 1)
                maxones--;
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}

