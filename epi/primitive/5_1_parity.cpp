#include<stdio.h>
#include<iostream>
#include<unordered_map>

using namespace std;


#define PARITY_MASK 0xFF
#define PARITY_MASK_BITS 8
unordered_map<unsigned short, short> parity_map;

short parity_linear(unsigned long long x)
{
	short parity = 0;
	while (x)
	{
		parity ^= x&1;
		x>>=1;
	}
	return parity;
}

short parity_linear_noshift(unsigned long long x)
{
	short parity = 0;
	while (x)
	{
		parity ^= 1;
		x = x & (x-1);
	}
	return parity;
}

short parity_cache(unsigned long long x)
{
	short parity = 0;
	while (x)
	{
		parity ^= (parity_map[x & PARITY_MASK]);
		x = x >> PARITY_MASK_BITS;
	}

	return parity;
}

short parity_xor(unsigned long long x)
{
  x ^= x>>32;
  x ^= x>>16;
  x ^= x>>8;
  x ^= x>>4;
  x ^= x>>2;
  x ^= x>>1;

  return x&0x1;
}

void initialize_parity_cache()
{
	for (int i = 0; i <= PARITY_MASK; i++)
		parity_map[i] = parity_xor(i);
}

int main()
{
  unsigned long long num;
  cout << "Enter number:";
  cin >> num;
  initialize_parity_cache();
  cout << "Parity of " << num << " is " << parity_xor(num) << endl;
  cout << "Parity of " << num << " is " << parity_linear(num) << endl;
  cout << "Parity of " << num << " is " << parity_linear_noshift(num) << endl;
  cout << "Parity of " << num << " is " << parity_cache(num) << endl;
  return 0;
}
