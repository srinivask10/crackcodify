#include <iostream>

using namespace std;

void read_string(string &str)
{
	cout << "Enter string: " << endl;
	cin >> str;
}

void read_int(int &n)
{
	cout << "Enter integer number: " << endl;
	cin >> n;
}


int get_number_from_string(string &str)
{
	int n = 0;
	for (int i = (str[0] == '-') ? 1 : 0; i < str.size(); i++)
		n = (n*10) + (str[i]-'0');
	
	return (str[0]=='-') ? -n : n;
}

string get_string_from_number(int num)
{
	string str;
	char ch;
	bool neg = (num < 0);

	if (neg)
		num = -num;

	while (num)
	{
		ch = (num%10) + '0';
		str.push_back(ch);
		num=num/10;
	}
	
	if (neg)
		str.push_back('-');

	for (int i = 0, j = str.length()-1; i < j; i++, j--)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}

	return str;
}

int main()
{
	int num;
	string str;

	read_string(str);
	read_int(num);

	cout << "Number from string [" << str <<"] is " << get_number_from_string(str) << endl;
	cout << "String from number [" << num <<"] is " << get_string_from_number(num) << endl;

	return 0;
}

