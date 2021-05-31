#include <iostream>

//__REVISIT_TO_UNDERSTAND_PROPERLY__

/*
Count path from start point to end point in a board game using a dice with possible values 1 to 6.
*/

using namespace std;

int count_path_maze(int n, int i, int j)
{
    if (i == n-1 && j == n-1)
        return 1;
    
    if (i >= n || j >= n)
        return 0;

    return (count_path_maze(n, i+1, j) + count_path_maze(n, i, j+1));
}

int main()
{
    cout << count_path_maze(4, 0, 0) << endl;
    return 0;
}

