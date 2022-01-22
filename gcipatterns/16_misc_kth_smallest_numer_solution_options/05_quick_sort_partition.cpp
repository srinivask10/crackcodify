using namespace std;
 
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(vector<int> &nums, int k) {
    return findKthSmallest(nums, k, 0, nums.size()-1);
  }

  static int findKthSmallest(vector<int> &nums, int k, int low, int high)
  {
    int pivotidx = randompartition(nums, low, high);
    if (pivotidx == k-1)
      return nums[pivotidx];

    if (pivotidx > k-1)
      return findKthSmallest(nums, k, low, pivotidx-1);

    return findKthSmallest(nums, k, pivotidx+1, high);
  }

  static int partition(vector<int> &nums, int low, int high)
  {
    if (low == high)
      return low;

    int pivot = nums[high];
    for (int i = low; i < high; i++)
    {
      if (nums[i] < pivot)
      {
        swap(nums[i], nums[low]);
        low++;
      }
    }
    swap(nums[low], nums[high]);
    return low;
  }

  static int randompartition(vector<int> &nums, int low, int high)
  {
    if (low == high)
      return low;

    srand(time(0));
    int pidx = low + rand() % (high - low);
    swap(nums[pidx], nums[high]);

    int pivot = nums[high];
    for (int i = low; i < high; i++)
    {
      if (nums[i] < pivot)
      {
        swap(nums[i], nums[low]);
        low++;
      }
    }
    swap(nums[low], nums[high]);
    return low;
  }


};

int main(int argc, char *argv[]) {
  vector<int> vec = {1, 5, 12, 2, 11, 5};
  int result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;
 
  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vec, 4);
  cout << "Kth smallest number is: " << result << endl;
 
  vec = {5, 12, 11, -1, 12};
  result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;
}

