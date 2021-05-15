#include <iostream>
#include <unordered_map>

using namespace std;

bool can_write_letter(string &letter, string &magazine)
{
	unordered_map<char, int> magazine_chars;

	for (auto ch : magazine)
		magazine_chars[ch]++;

	for (auto ch:letter)
	{
		if (magazine_chars[ch])
			magazine_chars[ch]--;
		else
			return false;
	}

	return true;
}

bool can_write_letter_optimized(string &letter, string &magazine)
{
	unordered_map<char, int> letter_chars;

	for (auto ch : letter)
		letter_chars[ch]++;

	for (auto ch : magazine)
	{
		unordered_map<char, int>::iterator it = letter_chars.find(ch);
		if (it != letter_chars.end())
		{
			it->second--;
			if (it->second == 0)
			{
				letter_chars.erase(it);
				if (letter_chars.empty())
					break;
			}
		}
	}


	return letter_chars.empty();
}



int main()
{
	string letter, magazine;
	cout << "Enter Letter: " << endl;
	cin >> letter;

	cout << "Enter Magazine: " << endl;
	cin >> magazine;

	cout << "Can write letter : " << can_write_letter(letter, magazine) << endl;
	cout << "Can write lettero: " << can_write_letter_optimized(letter, magazine) << endl;

	return 0;
}
