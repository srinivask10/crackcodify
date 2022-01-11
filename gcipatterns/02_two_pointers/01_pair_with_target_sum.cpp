using namespace std; 
#include <iostream>
#include <vector> 

class PairWithTargetSum { 
    public:  
    static pair<int, int> search(const vector<int>& arr, int targetSum) 
    {    
        int start = 0, end = arr.size()-1;
        int sum;
        while (start < end)
        {
            sum = arr[start]+arr[end];
            if (sum == targetSum)
                return make_pair(start, end);
            else if (sum > targetSum)
                end--;
            else
                start++;
        }
        return make_pair(-1, -1);  
    }
};

int main(int argc, char *argv[]) {  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;}
