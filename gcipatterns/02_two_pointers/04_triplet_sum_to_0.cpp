using namespace std;
 
#include <algorithm>
#include <iostream>
#include <vector>
 
class TripletSumToZero {
 public:
 static void find_triplet(vector<int> &arr, int idx, int sum, vector<vector<int>> &triplets)
 {
   int start = idx + 1;
   int end = arr.size() - 1;

   while (start < end)
   {
     int duosum = arr[start] + arr[end];
     if (duosum == sum)
     {
       triplets.push_back({-sum, arr[start], arr[end]});
       start++;
       end--;
       while (start < end && arr[start] == arr[start - 1])  
        start++;
       while (start < end && arr[end] == arr[end + 1])  
        end--;
     }
     else if (duosum < sum)
     {
       start++;
     }
     else
     {
       end--;
     }


   }

 }

  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
      if (i > 0 && arr[i] == arr[i - 1]) 
        continue;
      
      find_triplet(arr, i, -arr[i], triplets);

    }

    return triplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;
 
  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}

