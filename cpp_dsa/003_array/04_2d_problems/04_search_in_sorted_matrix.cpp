#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int searchnum;
    cin >> searchnum;

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    int found = 0;
    int i = 0, j = n-1;
    while (i < n && j >= 0)
    {
        if (a[i][j] == searchnum)
        {
            cout << "Found at " << i << " " << j << " location." << endl;
            found = 1;
            break;
        }
        else if (a[i][j] < searchnum)
        {
            i++;
        }
        else if (a[i][j] > searchnum)
        {
            j--;
        }
    }

    if (!found)
        cout << "Not found" << endl;

    return 0;
}
