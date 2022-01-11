#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    unsigned int cnt, sal;
    while (t--)
    {
        cin >> cnt;
        vector<unsigned int> emp;
        set<unsigned int> empset;
        unsigned int done = 0, skip;
        set<unsigned int> allgcd;

        unsigned int notes = 0, maxsal = 0, minsal = UINT_MAX, minnotes = UINT_MAX;

        for (int i = 0; i < cnt; i++)
        {
            cin >> sal;
            emp.push_back(sal);
            empset.insert(sal);
            maxsal = max(sal, maxsal);
            minsal = max(sal, minsal);
        }

        for (auto empi:empset)
        //for (int i = 0; i < cnt; i++)
        {
            skip = empi;
            unsigned int salgcd = 0;
            done = 0;

            //cout << " skip:" << skip << endl;
            //for (int j = 0; j < cnt; j++)
            for (auto empj:empset)
            {
                if (!done && empj == skip)
                    done = 1;
                else
                {
                    if (!salgcd)
                    {
                        salgcd = empj;
                        //cout << "setting salgcd:" << salgcd << endl;
                    }
                    else
                    {
                        salgcd = __gcd(salgcd, empj);
                        //cout << "setting salgcd:" << salgcd << " emp:" << emp[j] << endl;
                    }
                }
            }
            //cout << "salgcd:" << salgcd << " skip:" << skip << endl;
            allgcd.insert(salgcd);
        }

        //cout << "maxgcd:" << maxgcd << endl;
        for (auto thisgcd : allgcd)
        {
            unsigned int skipped = 0, minrepeat = 0, div, thismod, ignore = 0, nodivrepeat = 0;
            notes = 0;
            
            //cout << "thisgcd:" << thisgcd << endl;
            for (int i = 0; i < cnt; i++)
            {
                
                thismod = emp[i] % thisgcd;
                if (thismod && !nodivrepeat)
                {
                    nodivrepeat = 1;
                }
                else if (thismod && nodivrepeat)
                {
                    ignore = 1;
                    break;
                }

//                if (skipped || (emp[i] % thisgcd == 0))
                {
                    div = (emp[i] / thisgcd);
                    if (div)
                    {
                        //cout << "emp1:" << emp[i] << endl;
                        notes += div;
                    }
                    else if (!minrepeat)
                    {
                        //cout << "emp2:" << emp[i] << endl;
                        minrepeat = 1;
                        notes++;
                    }
                    else
                    {
                        //cout << "emp3:" << emp[i] << endl;
                        ignore = 1;
                        break;
                    }
                    //cout << "notes:" << notes << " emp[i]" << emp[i] << "\n";
                }
  //              else
                {
                    skipped = 1;
                }

                
            }

            if (ignore)
                continue;
                
            //cout << "notesbef:" << notes << "\n";
            if (!minrepeat)
            {
                if ((thisgcd % thisgcd) == 0)
                {
                    notes = (notes - (maxsal / thisgcd)) + 1;
                }
                else if (nodivrepeat)
                    notes++;
            }
            else
            {
                notes++;
            }

            //cout << "notes:" << notes << "\n";
            minnotes = min(minnotes, notes);
        }

        //cout << "final notes:" << notes << "\n";
        cout << minnotes << "\n";
    }

    return 0;
}


