#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        ll n, b;
        cin >> n >> b;
        vector<int> v;
        while (n != 0)
        {
            if (n % 2 == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
            n /= 2;
        }
        ll p = 1;
        ll ans1 = 0;
        ll ans2 = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                if (i == b)
                {
                    ans1 += ans2 + 1;
                }
                else if (i < b)
                {
                    ans2 += pow((ll)2,(ll)i);
                }
                else
                {
                    ans1 += pow((ll)2,(ll)i-1);
                }
            }
        }
        cout<<ans1<<"\n";
    }
}