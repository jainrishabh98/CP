#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int c[2002][2002];
map <pair<int,int>,int> vis;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n;
        vis.clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> c[i][j];   
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int cc = c[i][2];
            if (vis.find({i,cc})==vis.end() && vis.find({cc,i})==vis.end() )
            {
                cout << i << " " << cc << "\n";
                vis[{i,cc}] = 1;
                vis[{cc,i}] = 1;
            }
        }
        cout<<"\n";
    }
}
