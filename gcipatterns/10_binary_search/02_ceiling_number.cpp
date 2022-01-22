using namespace std;
 
#include <iostream>
#include <vector>
 
class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    
      int low, high, mid;

      low = 0;
      high = arr.size()-1;

      while (low <= high)
      {
          mid = low + (high - low)/2;
          if (key == arr[mid])
            return mid;
          else if (key < arr[mid])
            high = mid - 1;
          else
            low = mid + 1;
      }

    return (low < arr.size())?low:-1;

  }
};
 
int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}

