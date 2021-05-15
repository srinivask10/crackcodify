#include <iostream>
#include <unordered_map>

using namespace std;

#define BIT_MASK 0xFFFF

//NUM_BITS and MAX_NUMBER_BITS should be integer dividable. Otherwise this solution will fail.
#define NUM_BITS 16
#define MAX_NUMBER_BITS 64

unordered_map<unsigned short, unsigned short> cache;

unsigned short reverse_bits_short(unsigned short n)
{
	for (int i = 0; i < (NUM_BITS/2); i++)
	{
		if (((n >> i) & 0x1) != ((n >> (NUM_BITS-1-i)) & 0x1))
		{
			short bmask = (0x1 << i) | (0x1 << (NUM_BITS-1-i));
			n ^= bmask;
		}
	}
	return n;
}

void build_cache()
{
	for (unsigned short i = 0; i < BIT_MASK; i++)
		cache[i] = reverse_bits_short(i);
}



unsigned long long reverse_bits_number(unsigned long long n)
{
	unsigned long long rev = 0;
	int i = 0;
	
	do	
	{
		rev 	|= 	(cache[n & BIT_MASK]);
		rev 	<<= 	NUM_BITS;
		n 	>>= 	NUM_BITS;
		i 	+= 	NUM_BITS;
	} while (i < (MAX_NUMBER_BITS-NUM_BITS));		//Since we need to left shift only thrice in case of 64 bits number with 16 bit cache.

	return rev;
}

int main()
{
	unsigned long long n;
	cin >> n;
	build_cache();
	cout << reverse_bits_number(n) << endl;
	return 0;
}
