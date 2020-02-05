#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[26][200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    for(int i=0;i<26;i++)
    {
        if(s[0] - 'a' == i)
            pre[i][0]++;
        for(int j=1;j<n;j++)
        {
            pre[i][j] = pre[i][j-1];
            if(s[j]-'a' == i)
                pre[i][j]++;
        }
    }
    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        if(s[r]!=s[l] || r-l+1 == 1)
            cout<<"Yes\n";
        else
        {
            int cnt = 0;
            for(int i=0;i<26;i++)
            {
                int aaa = pre[i][r];
                if(l > 0)
                    aaa -= pre[i][l-1];
                if(aaa > 0)
                    cnt++;
            }
            if(cnt >= 3)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    }
}