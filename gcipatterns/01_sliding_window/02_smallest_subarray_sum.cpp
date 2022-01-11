using namespace std; 
#include <iostream>
#include <limits>
#include <vector> 
#include <algorithm> 

class MinSizeSubArraySum 
{ 
    public:  
    static int findMinSubArray(int S, const vector<int>& arr) 
    {
        int start = 0, end, smallest = numeric_limits<int>::max(), sum = 0;
        //Exact Sum.
        for (end = start; end < arr.size(); end++) {
            if (sum == S)
                smallest = min(end-start, smallest);

            sum += arr[end];
            
            while (sum > S)
                sum -= arr[start++];
        }

        //Greater than sum.      
        /*for (end = start; end < arr.size(); end++) {
            sum += arr[end];
            while (sum >= S) {
                smallest = min(end-start+1, smallest);
                sum -= arr[start++];
            }
        }*/
        return smallest == numeric_limits<int>::max() ? 0 : smallest;
    }
};

int main(int argc, char* argv[]) {  int result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{2, 1, 5, 2, 6, 2});  cout << "Smallest subarray length: " << result << endl;  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 6, 2, 8});  cout << "Smallest subarray length: " << result << endl;  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});  cout << "Smallest subarray length: " << result << endl;} 

