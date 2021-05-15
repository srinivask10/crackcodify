#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define SIZE 500

struct file_sort_heap
{
	int data;
	int source;
};

file_sort_heap my_heap[SIZE];
int cur_heap_size = 0;

void swap(file_sort_heap &entry1, file_sort_heap &entry2)
{
	file_sort_heap temp = entry1;
	entry1 = entry2;
	entry2 = temp;
}

void heapify_up(int index)
{
	while (index > 0)
	{
		if (my_heap[index].data < my_heap[(index-1)/2].data)
			swap(my_heap[index], my_heap[(index-1)/2]);
		else
			break;
		index = (index-1)/2;
	}
}

void heap_insert(file_sort_heap entry)
{
	if (cur_heap_size >= SIZE)
		return;
	my_heap[cur_heap_size] = entry;
	heapify_up(cur_heap_size);
	cur_heap_size++;
}

void heapify_down(int index)
{
	int mc_index;

	while (index < cur_heap_size)
	{
		mc_index = index*2+1;
		if (mc_index >= cur_heap_size)
			break;

		if (mc_index+1 < cur_heap_size && my_heap[mc_index].data > my_heap[mc_index+1].data)
			mc_index++;

		if (my_heap[index].data > my_heap[mc_index].data)
			swap(my_heap[index], my_heap[mc_index]);
		else
			break;

		index = mc_index;
	}
}

file_sort_heap heap_get_min()
{
	file_sort_heap entry;
	entry.data = entry.source = -1;

	if (cur_heap_size > 0)
	{
		entry = my_heap[0];
		my_heap[0] = my_heap[cur_heap_size-1];
		cur_heap_size--;
		heapify_down(0);
	}

	return entry;
}

void print_heap()
{
	cout << "Heap Size:" << cur_heap_size << " ";
	for (int i = 0; i < cur_heap_size; i++)
		cout << my_heap[i].data << ":" << my_heap[i].source << " ";
	cout << endl;
}

int main()
{
	fstream rfile[SIZE];
	int i, num;
	string str;
	char path[100];
	file_sort_heap entry;

	for (i = 0; i < SIZE; i++)
	{
		sprintf(path, "./random/files/file_%d.txt", i);
		rfile[i].open(path, ios::in);
	}

	for (i = SIZE-1; i >= 0; i--)
	{
		rfile[i] >> str;
		entry.data = atoi(str.c_str());
		entry.source = i;
		heap_insert(entry);
	}

	fstream ofile;
        ofile.open("output.txt", ios::out);
	while ((entry = heap_get_min()).data != -1)
	{
		ofile << entry.data << endl;
		if (rfile[entry.source] >> entry.data)
			heap_insert(entry);
	}

	return 0;
}

