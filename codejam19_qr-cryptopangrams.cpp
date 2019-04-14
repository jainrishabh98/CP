#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int n, l;
        cin >> n >> l;
        long long int a[l], b[l + 1];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < l; i++)
            cin >> a[i];
        set<long long int> poss;
        for (int i = 0; i < l - 1; i++)
        {
            if (a[i] == a[i + 1] && b[i] == 0)
                continue;
            else if (a[i] == a[i + 1])
            {
                b[i + 1] = a[i] / b[i];
            }
            else
            {
                b[i + 1] = __gcd(a[i], a[i + 1]);
            }
        }
        int k = 0;
        while (b[k] == 0 && k != l + 1)
        {
            k++;
        }
        int i = k;
        while (k != 0)
        {
            b[k - 1] = a[k - 1] / b[k];
            k--;
        }
        for (; i < l + 1; i++)
        {
            if (b[i] == 0)
            {
                b[i] = a[i - 1] / b[i - 1];
            }
        }
        for(int i=0;i<l+1;i++)
        {
            poss.insert(b[i]);
        }
        map<long long int, char> mp;
        int cnt = 0;
        for (auto ll : poss)
        {
            // cout<<ll<<" ";
            mp[ll] = (char)('A' + cnt);
            cnt++;
            if (cnt == 26)
                break;
        }
        // cout<<"\n";
        string ans;
        for (int ii = 0; ii < l + 1; ii++)
        {
            ans.push_back(mp[b[ii]]);
        }
        cout << "Case #" << j << ": " << ans << "\n";
    }
}