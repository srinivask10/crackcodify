using namespace std;
 
#include <iostream>
#include <vector>
 
class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int low, high, last;
    low = 0;
    high = last = arr.size()-1;

    while (low <= high)
    {
        int ls = arr[low]*arr[low];
        int hs = arr[high]*arr[high];

        if (ls > hs)
        {
            squares[last--] = ls;
            low++;
        }
        else
        {
            squares[last--] = hs;
            high--;
        }
    }
    return squares;
  }
};


int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
 
  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

