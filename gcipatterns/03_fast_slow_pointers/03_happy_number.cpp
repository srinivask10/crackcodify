using namespace std;
 
#include <iostream>
 
class HappyNumber {
 public:
  static int sumsquares(int num) {
      int square = 0;
      while (num != 0)
      {
          int digit = num % 10;
          square = square + (digit * digit);
          num /= 10;
      }
      return square;
  }
  static bool find(int num) {
      int slow, fast;
      slow = fast = num;

    do
    {
        slow = sumsquares(slow);
        fast = sumsquares(sumsquares(fast));
    } while (slow != fast);

    return slow == 1;
  }
};
 
int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}

