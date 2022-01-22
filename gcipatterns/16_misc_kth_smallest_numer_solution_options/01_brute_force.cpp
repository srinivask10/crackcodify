using namespace std;
 
#include <iostream>
#include <limits>
#include <vector>
 
class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    
    int current = numeric_limits<int>::max(), prev = numeric_limits<int>::min(), previdx = -1, curidx = -1;

      for (int i = 0; i < k; i++)
      {
          for (int j = 0; j < nums.size(); j++)
          {
              if (nums[j] > prev && nums[j] < current)
              {
                curidx = j;
                current = nums[j];
              }
              else if (nums[j] == prev && previdx != j)
              {
                  current = nums[j];
                  curidx = j;
                  break;
              }
          }
          prev = current;
          previdx = curidx;
          current = numeric_limits<int>::max();
      }

    return prev;
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;
 
  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;
 
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}

