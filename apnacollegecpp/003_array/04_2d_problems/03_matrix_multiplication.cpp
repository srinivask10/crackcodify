#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
    int n1, n2, n3;

    //cin >> n1 >> n2 >> n3;

    n1 = n2 = n3 = 4;

    //output matrix
    int a3[n1][n3];

    int a1[n1][n2] = {  { 1, 1, 1, 1 },
            { 2, 2, 2, 2 },
            { 3, 3, 3, 3 },
            { 4, 4, 4, 4 } };

    int a2[n2][n3] = {  { 1, 1, 1, 1 },
            { 2, 2, 2, 2 },
            { 3, 3, 3, 3 },
            { 4, 4, 4, 4 } };

/*
    //read matrix 1
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            cin >> a1[i][j];

    //read matrix 2
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n3; j++)
            cin >> a2[i][j];

*/

    int sum;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            sum = 0;
            for (int k = 0; k < n2; k++)
            {
                sum += (a1[i][k] * a2[k][j]);
            }
            a3[i][j] = sum;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << a3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    return 0;
}

