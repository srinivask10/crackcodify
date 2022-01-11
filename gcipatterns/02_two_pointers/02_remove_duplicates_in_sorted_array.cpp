using namespace std; 
#include <iostream>
#include <vector> 

class RemoveDuplicates { 
    public:  
    static int remove(vector<int>& arr) 
    {
        if (arr.size() <= 1)
            return arr.size();

        int nsize = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i-1] == arr[i])
                continue;
            arr[nsize] = arr[i];
            nsize++;            
        }

        return nsize;
    }
};


int main(int argc, char* argv[]) {  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;   arr = vector<int>{2, 2, 2, 11};  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;} 

