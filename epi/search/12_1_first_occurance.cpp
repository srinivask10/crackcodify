#include <iostream>
#include <vector>

using namespace std;

void read_vector(vector<int> &a)
{
	int num = 0, n;

	cout << "Enter number of elements in array: ";
	cin >> num;

	cout << "Enter " << num << " elements: " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		a.push_back(n);
	}
}


int find_first_occurance(vector<int> &a, int num)
{
	int min_found_index = a.size();

	int low = 0, high = a.size()-1, mid = (high+low)/2;
	while(low <= high)
	{
		if (a[mid] == num)
		{
			if (mid < min_found_index)
				min_found_index = mid;
			if (mid == 0 || a[mid-1] != num)
				break;
		}
		
		if (num <= a[mid])
			high = mid-1;
		else
			low=mid+1;

		mid = (low+high)/2;
	}

	if (min_found_index == a.size())
		return -1;

	return min_found_index;
}

int main()
{
	int num;
	vector<int> arr;

	read_vector(arr);

	cout << "Enter number to search: "; 
	cin >> num;

	int index = find_first_occurance(arr, num);
	if (index != -1)
		cout << "Number " << num << " found at index " << index << endl;
	else
		cout << "Number " << num << " not found" << endl;
}

