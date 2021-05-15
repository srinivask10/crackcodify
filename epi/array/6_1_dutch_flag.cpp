#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void print_vector(vector<int> &arr)
{
	cout << "Printing array (length:" << arr.size() << "): " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void dutch_flag(vector<int> &a, int pivot_index)
{
	int i;
	int pivot = a[pivot_index];
	
	int less = 0;
	for (i = 0; i < a.size(); i++)
	{
		if (a[i] < pivot)
			swap(a[i], a[less++]);
	}

	int more = a.size()-1;
	for (i = a.size()-1; i >= 0; i--)
	{
		if (a[i] > pivot)
			swap(a[i], a[more--]);
	}
}

/*
 * Partition the array in 4 parts: *)less than *)equal to *)unclassified *)greater than
 *
 *  consider following indexes: 
 *  - bottom group: 0 to smaller-1
 *  - middle group: smaller to equal-1
 *  - unclassified: eqaul to larger-1
 *  - top group:    larger to size-1
*/

void dutch_flag_single_pass(vector<int> &a, int pivot_index)
{
	int pivot = a[pivot_index];
	int smaller, equal, larger;

	smaller = equal = 0;
	larger = a.size()-1;

	while (equal <= larger)
	{
		if (a[equal] < pivot)
			swap(a[equal++], a[smaller++]);
		else if (a[equal] == pivot)
			equal++;
		else // a[equal] > pivot
			swap(a[equal], a[larger--]);
	}
}

int main()
{
	int pivot_index, num_count, num, i;
	vector<int> arr;

	cout << "Enter total numbers in array:" << endl;
	cin >> num_count;

	cout << "Enter " << num_count << " numbers:" << endl;
	for (i = 0; i < num_count; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	do 
	{
		cout << "Enter valid pivot index from 0 to " << num_count-1 << ":" << endl;
		cin >> pivot_index;
	
	} while(pivot_index < 0 || pivot_index >= num_count);


	print_vector(arr);
	//dutch_flag(arr, pivot_index);
	dutch_flag_single_pass(arr, pivot_index);
	print_vector(arr);

	return 0;
}

