using namespace std; 
#include <iostream>
#include <vector> 
#include <algorithm> 

class MaxSumSubArrayOfSizeK 
{ 
    public:  
    static int findMaxSumSubArray(int k, const vector<int>& arr) 
    {
        int maxSum = 0, cursum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (i < k)
            {
                cursum = cursum + arr[i];
            }
            else
            {
                cursum += arr[i];
                cursum -= arr[i-k];
            }   
            maxSum = max(cursum, maxSum);                     
        }

        return maxSum;  
    }
};


int main(int argc, char* argv[]) {  cout << "Maximum sum of a subarray of size K: "       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;  cout << "Maximum sum of a subarray of size K: "       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;}