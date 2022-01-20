using namespace std;
 
#include <iostream>
#include <vector>
 
class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); )
    {
        if (nums[i]-1 != i)
            swap(nums[i], nums[nums[i]-1]);
        else
            i++;
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
 
  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
 
  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}
 

