#include <iostream>
//#include <string>

using namespace std;

void tower_of_hanoi(int ndisks, char from, char helper, char to)
{
    if (ndisks == 1)
    {
        cout << "Move from " << from << " to " << to << endl;
        return;
    }

    tower_of_hanoi(ndisks-1, from, to, helper);
    cout << "Move from " << from << " to " << to << endl;
    tower_of_hanoi(ndisks-1, helper, from, to);
}

int main()
{
    tower_of_hanoi(3, 'A', 'B', 'C'); 
    return 0;
}

