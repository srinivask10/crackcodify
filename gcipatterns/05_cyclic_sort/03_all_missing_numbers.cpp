using namespace std;
 
#include <iostream>
#include <vector>
 
class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    int i = 0, j;
    while (i < nums.size())
    {
        j = nums[i]-1;
        if (j < nums.size() && nums[i] != nums[j])
            swap(nums[i], nums[j]);
        else
            i++;
    }

    i = 0;
    while (i < nums.size())
    {
        if (nums[i] != i+1)
            missingNumbers.push_back(i+1);
        i++;
    }

    return missingNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
 
  v1 = {2, 4, 1, 2};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
 
  v1 = {2, 3, 2, 1};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}
 

