using namespace std;
 
#include <iostream>
#include <vector>
 
class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
        if (!arr.size())
            return -1;

      int xornum = arr[0];
      for (int i = 1; i < arr.size(); i++)
          xornum = xornum ^ arr[i];

      return xornum;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}

