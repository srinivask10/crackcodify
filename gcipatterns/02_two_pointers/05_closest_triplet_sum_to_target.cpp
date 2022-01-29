using namespace std;
 
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
 
class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
      int smallestdiff = numeric_limits<int>::max();
      for (int i = 0; i < arr.size(); i++)
      {
          int start = i + 1;
          int end = arr.size() - 1;
          while (start < end)
          {
              int sum = targetSum - (arr[i] + arr[start] + arr[end]);
              if (sum == 0)
                return targetSum;
              
              smallestdiff = min(smallestdiff, abs(sum));

              if (sum > 0)
                start++;
              else
                end--;

          }
      }

    return targetSum - smallestdiff;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {-2, 0, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 2) << endl;
  vec = {-3, -1, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
}

