using namespace std;
 
#include <iostream>
#include <vector>
 
class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
      if (!nums.size())
        return vector<int>{-1, -1};

      int xornum = nums[0];
      for (int i = 1; i < nums.size(); i++)
        xornum ^= nums[i];
    
        int commonbit = 1;
        while ((xornum & commonbit) == 0)
            commonbit = commonbit << 1;

        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & commonbit)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }


    return vector<int>{num1, num2};
  }
};
 
int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
 
  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}

