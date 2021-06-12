#include <iostream>

using namespace std;

void all_subsets_of_set(int a[], int n)
{
    //Loop from 0 to 2^n.
    for (int i = 0; i < (1<<n); i++)
    {
        cout << "{"; 
        for (int j = 0; j < n; j++)
        {
            if ((1<<j) & i)
            {
                cout << a[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main()
{

    int a[] = {1, 2, 3};
    all_subsets_of_set(a, sizeof(a)/sizeof(a[0]));
    
    return 0;
}