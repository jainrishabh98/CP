#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll a[m][5] ={0};
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            a[j][s[j]-'A']++;
        }
    }
    ll sc[m];
    for(int i=0;i<m;i++)
    {
        cin>>sc[i];
    }
    ll ans = 0;
    for(int i=0;i<m;i++)
    {
        ll mx = 0;
        for(int j=0;j<5;j++)
        {
            mx = max(mx,a[i][j]);
        }
        ans += (mx*sc[i]);
    }
    cout<<ans;
}