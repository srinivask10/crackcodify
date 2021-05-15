#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct max_count
{
	int max;
	int count;
};

class mystack
{
	int *a;
	int top;
	int capacity;

	struct max_count *max;
	int max_top;
	int capacity_max;
public:
	mystack();
	mystack(int size);
	~mystack();

	void 	push(int data);
	int 	pop();
	int 	peep();
	int 	getmax();
	void 	print_stack_diagnostics();
};

mystack::mystack()
{
	capacity = 1;

	a = new int[capacity];
	top = -1;
	memset(a, 0, sizeof(*a)*capacity);

	capacity_max = 1;
	max = new struct max_count[capacity_max];
	max_top = -1;
	memset(max, 0, sizeof(*max)*capacity_max);
}

mystack::~mystack()
{
	delete [] a;
	a = NULL;
	top = -1;
	capacity = 0;

	delete [] max;
	max = NULL;
	max_top = -1;
	capacity_max = 0;
}

void mystack::print_stack_diagnostics()
{

	int i;

	cout << "Actual Stack:" << endl;
	for (i = 0; i <= top; i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "Max Count Stack:" << endl;
	for (i = 0; i <= max_top; i++)
		cout << max[i].max << ":" << max[i].count << " ";
	cout << endl;

}

void mystack::push(int data)
{
	//if we exceed the capacity, reallocate the array.
	if (top == -1)
	{
		a[0] = data;
		top++;
	}
	else 
	{
		if (++top == capacity)
		{
			int *t = new int [capacity*2];
			for (int i = 0; i < capacity; i++)
			{
				cout << "Resizing copy: [" << i << "]: " << a[i] << endl;
				t[i] = a[i];
			}

			delete [] a;
			a = t;
			capacity *= 2;
		}

		a[top] = data;
	}


	
	if (max_top == -1)
	{
		max[0].max = data;
		max[0].count = 1;
		max_top++;
	}
	else
	{
		if (max[max_top].max == data)
			max[max_top].count++;
		else if (max[max_top].max < data) 
		{
			if (++max_top == capacity_max)
			{
				struct max_count *t = new struct max_count[capacity_max*2];
				for (int i = 0; i < capacity_max; i++)
					t[i] = max[i];

				delete [] max;
				max = t;
				capacity_max *= 2;
			}

			max[max_top].max = data;
			max[max_top].count = 1;
		}
	}
}

int mystack::pop()
{
	if (top == -1)
		return -1;

	int data = a[top];
	top--;
	if (data == max[max_top].max)
	{
		max[max_top].count--;
		if (!max[max_top].count)
			max_top--;
	}
	return data;
}

int mystack::peep()
{
	if (top != -1)
		return a[top];
	return -1;
}

int mystack::getmax()
{
	if (max_top != -1)
		return max[max_top].max;
	return -1;
}

void print_options()
{
	cout << endl;
	cout << endl;
	cout << "Stack options:" << endl;
	cout << "\t1.\tPush" << endl;
	cout << "\t2.\tPop" << endl;
	cout << "\t3.\tPeep" << endl;
	cout << "\t4.\tGetMax" << endl;
	cout << "\t5.\tPrintStackDiagnostics" << endl;
	cout << "\t0.\tExit" << endl;
	cout << "\tEnter option: ";
}


int main()
{
	mystack s;
	int op;
	int num;

	do 
	{
		print_options();
		cin >> op;
		switch(op)
		{
		case 1: 
			while (true)
			{
				cout << "Enter number to push (-1 to stop entering): ";
				cin >> num;
				if (num == -1)
					break;
				s.push(num);
			}
			break;
		case 2: 
			cout << "Popped: " << s.pop() << endl;
			break;
		case 3: 
			cout << "Peeped: " << s.peep() << endl;
			break;
		case 4: 
			cout << "Max: " << s.getmax() << endl;
			break;
		case 5: 
			s.print_stack_diagnostics();
			break;
		default:
			break;
		}
	}while(op != 0);

}
