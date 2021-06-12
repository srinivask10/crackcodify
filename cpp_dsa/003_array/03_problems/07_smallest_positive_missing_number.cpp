#include <iostream>
#include<algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

/*
    Given an  array of size N including 0, 
    Task is to find smallest +ve number missing from the array.




There are two important insights for solving this problem with constant space:
 1. For an array of size N, the solution is one of {1, 2, 3, ..., N+1}. So, for example, the smallest missing integer in
 an array of size 4, has to be one of {1, 2, 3, 4, 5}. (Sure enough, the solution to the example above, 
 {3, 4, -1, 1} is 2). Why? This is because of a famous mathematical principle, called The Pigeon Hole Principle.
 Assume, if possible, that the smallest positive missing integer in the array of size N is greater than N+1.
 For this to happen, every integer from 1 to N+1 must be present in the array. However, the array only has a
 size of N, and cannot accommodate N+1 integers, contradicting our initial assumption. 
 Hence, for an efficient algorithm, we can ignore all the elements of the array outside the interval [1, N+1].

 2. The second insight is that we can use the original array itself as a hash-table/set to store whether a number
 is present!. We can do that by simply changing the sign of the original number!. The smallest missing integer 
 can then be found by finding the first position in the array that stores a positive number, and returning its index.


Both of these insights will become clear by working out an example. Consider an array:
A = {1, -2, 3, -4, 5, -6, 7}
The size of the array is 7. And hence the only possible solution must be in [1, 8]. We can ignore all the numbers in the array outside this range. For doing that, we can reshuffle the array so that all the numbers in [1, 8] come to the front, and the rest are sent to the back. Like this:
A = {1, 7, 3, 5, -4, -6, -2}
For the next iteration, assume that the array indices start with 1 instead of the usual 0. We iterate from the left of the array, for every number i, we flip the sign of ith index of the array to negative.
The first element of above array is 1. Flipping the sign of the 1st index in the array gives us {-1, 7, 3, 5, -4, -6, -2}.
The second element of the array is 7. The sign of the 7th element is already negative, so we leave the array in-tact.
The third element of the array is 3. Flipping the sign of 3rd index of the array gives us {-1, 7, -3, 5, -4, -6, -2}.
The end of this iteration gives us the following array:
A = {-1, 7, -3, -5, -4, -6, -2}
What’s the first positive number is the array? 7. What’s its index in the array? 2 (Remember one-based indexing). As a result, the smallest missing positive integer in the array is (drumroll) 2.


*/


void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}


// It brings all elements from [1, n] to the beginning of the array, and the rest to the end.
// Returns the total number of elements within [1, n] in the array.
int shuffle(int a[], int n)
{
    int i, j;

    i = 0;      //start
    j = n-1;    //end
    while (i < j)
    {
        if (a[i] >= 1 && a[i] <= n)
        {
            i++;
        }
        else
        {
            swap(a[i], a[j]);
            j--;
        }
    }


    if (a[i] >= 1 && a[i] <= n)
        return i;

    return i-1;
}

int smallest_missing_positive(int a[], int n)
{
    int idx;
    //printarray(a, n);
    int present_till = shuffle(a, n);
    //printarray(a, n);

    if (present_till < 0)
        return 1;               //If all are negative or min element in array is n+1.

    for (int i = 0; i <= present_till; i++)
    {
        idx = abs(a[i])-1;
        a[idx] = -abs(a[idx]);
    }

    //printarray(a, n);

    for (int i = 0; i <= present_till; i++)
        if (a[i] > 0)
            return i+1;
    
    return n+1;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << smallest_missing_positive(arr, size) << endl;
    return 0;
}
