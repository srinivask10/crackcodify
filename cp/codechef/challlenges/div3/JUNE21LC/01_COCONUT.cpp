#include <iostream>
using namespace std;

int main() {
	int xa, xb, Xa, Xb;
	int t;
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
	    cin >> xa >> xb >> Xa >> Xb;
	    cout << ((Xa / xa) + (Xb / xb)) << "\n";
	}
	
	return 0;
}
