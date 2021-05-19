#include <iostream>

using namespace std;

#define ASC 0
#define DESC 1

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void selection_sort(int arr[], int n, int order)
{
    if (order != ASC && order != DESC)
        order = ASC;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((order == ASC && arr[i] > arr[j]) || (order == DESC && arr[i] < arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubble_sort(int arr[], int n, int order)
{
    if (order != ASC && order != DESC)
        order = ASC;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if ((order == ASC && arr[j] > arr[j+1]) || (order == DESC && arr[j] < arr[j+1]))
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void insertion_sort(int arr[], int n, int order)
{
    if (order != ASC && order != DESC)
        order = ASC;

    for (int i = 1; i < n; i++)
    {
        int current = arr[i];       //need to save this instead of using arr[i] directly, otherwise it may get overwritten by j+1 moving below
        int j = i-1;
        while (j >= 0 && ((order == ASC && current < arr[j]) || (order == DESC && current > arr[j])))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


int main()
{

    int order;      //asc=0, desc=1
    cin >> order;

    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];
    //printarray(arr, n);
    //selection_sort(arr, n, order);
    //bubble_sort(arr, n, order);
    insertion_sort(arr, n, order);
    printarray(arr, n);

    return 0;
}
