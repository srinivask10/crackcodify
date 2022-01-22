using namespace std;
 
#include <iostream>
#include <queue>
#include <vector>
 
class KthSmallestInMSortedArrays {
 public:
 struct ValCompare
 {
     bool operator() (const pair <int, pair<int, int>> n1, const pair <int, pair<int, int>> n2)
     {
         return (n1.first > n2.first);
     }
 };

  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    int result = -1;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ValCompare> minheap;
    
    for (int i = 0; i < lists.size(); i++)
        minheap.push(make_pair(lists[i][0], make_pair(i, 0)));

    int count = 0;
    while (!minheap.empty())
    {
        auto number = minheap.top();
        minheap.pop();

        if (++count == k)
            return number.first;

        if (number.second.second < lists[number.second.first].size()-1)
            minheap.push(make_pair(lists[number.second.first][number.second.second+1], make_pair(number.second.first, number.second.second+1)));
    }

    return -1;
  }
};
 
int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}

