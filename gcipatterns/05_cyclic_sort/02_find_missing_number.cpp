using namespace std;
 
#include <iostream>
#include <vector>
 
class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    int i = 0; 
    while (i < nums.size())
    {
        if (nums[i] != nums[nums[i]] && nums[i] < nums.size())
            swap(nums[i], nums[nums[i]]);
        else
            i++;
    }

    for (i = 0; i < nums.size(); i++)
        if (nums[i] != nums[nums[i]])
            return i;

    return -1;
  }
};


int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}

