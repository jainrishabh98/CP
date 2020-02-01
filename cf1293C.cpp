#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, r, c, c_id, c2;
    cin >> n >> q;
    int a[2][n + 2];
    memset(a, 0, sizeof(a));
    map<pair<int, int>, int> mp;
    while (q--)
    {
        cin >> r >> c;
        c_id = c;
        if (r == 2)
            c_id += n;
        r--;
        if (a[r][c] == 0)
        {
            a[r][c] = 1;
            c2 = c;
            if (r == 0)
                c2 += n;
            if (a[r ^ 1][c] == 1)
            {
                mp[{c_id, c2}] = 1;
            }
            if (a[r ^ 1][c - 1] == 1)
            {

                mp[{c_id, c2 - 1}] = 1;
            }
            if (a[r ^ 1][c + 1] == 1)
            {
                mp[{c_id, c2 + 1}] = 1;
            }
        }
        else
        {
            a[r][c] = 0;
            c2 = c;
            if (r == 0)
                c2 += n;
            if (a[r ^ 1][c] == 1)
            {
                if (mp.find({c_id, c2}) != mp.end())
                {
                    mp.erase({c_id, c2});
                }
                if (mp.find({c2, c_id}) != mp.end())
                {
                    mp.erase({c2, c_id});
                }
            }
            if (a[r ^ 1][c - 1] == 1)
            {
                if (mp.find({c_id, c2 - 1}) != mp.end())
                {
                    mp.erase({c_id, c2 - 1});
                }
                if (mp.find({c2 - 1, c_id}) != mp.end())
                {
                    mp.erase({c2 - 1, c_id});
                }
            }
            if (a[r ^ 1][c + 1] == 1)
            {
                if (mp.find({c_id, c2 + 1}) != mp.end())
                {
                    mp.erase({c_id, c2 + 1});
                }
                if (mp.find({c2 + 1, c_id}) != mp.end())
                {
                    mp.erase({c2 + 1, c_id});
                }
            }
        }
        if(mp.size()==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}