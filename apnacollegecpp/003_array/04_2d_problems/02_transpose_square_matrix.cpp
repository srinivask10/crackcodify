#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    return 0;
}

