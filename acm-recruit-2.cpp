#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt[10] = {0};
    for(int i=0;i<s.length();i++)
    {
        cnt[s[i]-'0']++;
    }
    ll ans = 1;
    ll m = 1e9 + 7;
    for(int i=0;i<n;i++)
    {
        (ans *= cnt[a[i]])%=m;
    }
    cout<<ans;
}