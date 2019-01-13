#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n<=0)
    {cout<<"0\n";return 0;}
    int x;
    int ans = 0;
    vector <int> visr;
    vector <int> visc;
    visr.assign(n+1,0);
    visc.assign(n+1,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 1)
            {
                if (visr[i] == 0 && visc[j] == 0)
                    ans++;

                visr[i] = 1;
                visr[i+1] = 1;
                visc[j] = 1;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}