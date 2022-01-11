#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MOD 1000000007
vector<unsigned long long> chefora_list;


bool is_chefora(unsigned long long n)
{
    unsigned long long rev = 0;
    int numdigits = 0;
    while (n)
    {
        rev = (rev*10) + (n%10);
        n /= 10;
        numdigits++;
    }
    if (numdigits%2 && rev == n)
        return true;
    return false;
}

void populate_chefora(int n)
{
    int idx = 1;
    unsigned long long num = 1;
    chefora_list.push_back(0);
    while (idx <= n)
    {
        if (is_chefora(num))
        {
            //chefora_list[idx] = num;
            chefora_list.push_back(num);
            idx++;
        }
        num++;
    }
    
    
    for (int i=0; i <= n; i++)
        cout << chefora_list[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
	unsigned long long l, r, powof;

	//populate_chefora(50);
	//populate_chefora(10001);
	
    while(t--)
    {
        cin >> l >> r;
        //cout << l << " " << r << "\n";
        powof = 0;
        for (int i = l+1; i <= r; i++)
        {
            powof += chefora_list[i];
        }
        //cout << power(l, powof) << endl;        
    }
    
    return 0;
}
