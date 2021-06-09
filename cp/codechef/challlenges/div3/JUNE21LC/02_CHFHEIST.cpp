#include <iostream>
using namespace std;

int main() {
	
	int t;
	long long D, d, P, Q, n, op, inc;
	
	cin >> t;
	
	while (t > 0)
	{
	    
	    cin >> D >> d >> P >> Q;
	    
	    inc = (D / d);
	    n = inc * (inc - 1) / 2;
	    
	    op = (D * P) + (n * d *  Q) + ((D % d) * inc * Q);
	    
	    cout << op << endl;
	    
	    t--;
	}
	
	return 0;
}
