#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ma[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll b, d;
    string a, c, t;
    cin >> b >> d >> a >> c;
    ll n = c.length();
    for(ll i=0;i<c.length();i++)
    {
        ll match =0;
        for(ll j=0;j<a.length() ;j++)
        {
            if(c[(i+match)%n]==a[j])match++;
        }
        ma[i]=match;   
    }
    ll total_character_matched = 0,match=0;
    for(ll i=0;i<b;i++)
    {
        total_character_matched+=ma[match];
        match = (match+ma[match])%n;
    }
    cout<<total_character_matched/(d*c.length());

}