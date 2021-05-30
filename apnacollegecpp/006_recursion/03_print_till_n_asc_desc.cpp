#include <iostream>
#include <algorithm>

using namespace std;

void print_till_n_asc(int n)
{
    if (n) {
        print_till_n_asc(n-1);
        cout << n << " " << endl;
    }
}

void print_till_n_desc(int n)
{
    if (n) {
        cout << n << " " << endl;
        print_till_n_desc(n-1);
    }
}

//asc = 0, desc = 1
void print_till_n_ascdesc(int n, int ascdesc)
{
    if (n) {
        if (ascdesc == 1)
            cout << n << " " << endl;
        print_till_n_ascdesc(n-1, ascdesc);
        if (ascdesc == 0)
            cout << n << " " << endl;
    }
}


int main()
{
    print_till_n_asc(10);
    print_till_n_desc(10);
    print_till_n_ascdesc(5, 1);
    print_till_n_ascdesc(5, 0);
    return 0;
}
