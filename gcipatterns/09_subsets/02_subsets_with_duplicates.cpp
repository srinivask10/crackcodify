using namespace std;
 
#include <algorithm>
#include <iostream>
#include <vector>
 
class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());

    sort(nums.begin(), nums.end());
    int start, end;
    for (int i = 0; i < nums.size(); i++)
    {
        start = 0;
        if (i > 0 && nums[i] == nums[i-1])
            start = end+1;
        end = subsets.size()-1;
        for (int j = start; j <= end; j++)
        {
            vector<int> set(subsets[j]);
            set.push_back(nums[i]);
            subsets.push_back(set);
        }
    }

    return subsets;
  }
};
 
int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
 
  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

