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
