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

void print_vector(vector<int> &a)
{
	cout << "Contents of array: " << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

#define MIN 0
#define MAX 1

int get_min_or_max(vector<int> a, int start, int end, int min_or_max)
{
	int min_max = a[start];
	for (int i = start+1; i <= end; i++)
		if ((min_or_max == MIN && min_max > a[i]) || min_or_max == MAX && min_max < a[i])
			min_max = a[i];

	return min_max;
}

int max_of_three(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	if (b > c)
		return b;
	return c;
}

void print_array(vector<int> &a, int low, int high)
{
	cout << "low: " << low << " high: " << high << endl;
	
	for (int i = low; i <= high; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << endl;
}


int buy_sell_divide(vector<int> a, int low, int high)
{
	if (low == high)
		return 0;

	int mid = ((high+low)/2);

	int min = get_min_or_max(a, low, mid, MIN);
	int max = get_min_or_max(a, mid+1, high, MAX);
	
	int profit = max-min;

	return max_of_three(buy_sell_divide(a, low, mid), buy_sell_divide(a, mid+1, high), profit);
}

int buy_sell_divide_approach(vector<int> a)
{
	return buy_sell_divide(a, 0, a.size()-1);
}

int buy_sell_linear_approach(vector <int> a)
{
	int min_till_now = a[0];
	int max_profit = 0;
	int cur_profit;

	for (int i = 1; i < a.size(); i++)
	{
		cur_profit = a[i]-min_till_now;
		if (cur_profit > max_profit)
			max_profit = cur_profit;

		if (min_till_now > a[i])
			min_till_now = a[i];
	}

	return max_profit;
}

int main()
{
	vector<int> arr;
	read_vector(arr);

	cout << buy_sell_divide_approach(arr) << endl;
	cout << buy_sell_linear_approach(arr) << endl;
}

