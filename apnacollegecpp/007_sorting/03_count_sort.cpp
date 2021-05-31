#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void count_sort(int a[], int n)
{
    int maxn = a[0];

    //Get max in array
    for (int i = 0; i < n; i++)
        maxn = max(maxn, a[i]);

    //create count array to store each number's count.
    int count_array[100] = { 0 };

    //Count occurances of number
    for (int i = 0; i < n; i++)
        count_array[a[i]]++;

    //Calculate start index of each number. It will be start_index + occurances of a number after this.
    for (int i = 1; i <= maxn; i++)
        count_array[i] += count_array[i-1];

    int op[n];
    //Go from end to start and start adding numbers at appropriate index.
    //THink why we need to go from end! 
    //Because, count_array has start_index + occurances. So, we go on decrementing the count_array as 
    //we go to the numbers till the start index of each number whenver it occured in array.
    for (int i = n-1; i >= 0; i--)
        op[--count_array[a[i]]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = op[i];

}

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

/* 
Time complexity will be O(n) or O(max_number_in_array). Since it depends on max number in array.
So, if the numbers are repeating  and there limit to max number in array, this is useful because you may avoid n^2 time 
and do it in O(n) or O(max_in_array).
*/

int main()
{
    int a[] = { 1,3,2,3,4,1,6,4,3 };
    int size = sizeof(a)/sizeof(a[0]);

    printarray(a, size);

    count_sort(a, size);

    printarray(a, size);

    return 0;
}
