using namespace std;
 
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result(nums.begin(), nums.begin() + k);
    make_heap(result.begin(), result.end(), greater<int>());
    
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > result.front())
        {
            pop_heap(result.begin(), result.end(), greater<int>());
            result.pop_back();
            result.push_back(nums[i]);
            push_heap(result.begin(), result.end(), greater<int>());
        }
    }
    return result;
  }
};
 
int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
 
  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

