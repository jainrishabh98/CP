#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m >= n - 1 && m <= 2 * (n + 1))
    {
        if(m<=n)
        {   int f= 0;
            for(int i=0;i<n+m;i++)
            {
                if(f==0)
                {
                    cout<<"0";
                    f=1;
                }
                else
                {
                    f=0;
                    cout<<"1";
                }
            }
        }
        else
        {
            int n2 = max(0,m - (n + 1) );
            int fl = 1;
            for (int i = 0; i < n + m; i++)
            {
                if (fl == 0)
                {
                    cout << "0";
                    fl = 1;
                }
                else
                {
                    fl=0;
                    if(n2>0)
                    {
                        cout<<"11";
                        i++;
                        n2--;
                    }
                    else
                    {
                        cout<<"1";
                    }
                }
            }
        }
        
    }
    else
        cout << "-1";
}