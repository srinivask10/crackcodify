using namespace std;
 
#include <iostream>
#include <vector>
 
class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int order = (arr[0] < arr[arr.size()-1])?0:1;
    int start = 0, end = arr.size()-1, mid;

    while (start <= end)
    {
        mid = start + (end-start)/2;
        if (key == arr[mid])
            return mid;
        else
        {
            if (order == 0)
            {
                if (key < arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (key < arr[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }
    return -1; 
  }
};
 
int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 100) << endl;
}

