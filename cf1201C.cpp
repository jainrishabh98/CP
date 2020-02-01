#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll k;
    cin>>k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll prefix = 0;
    ll md = a[n/2];
    int i;
    for(i=n/2+1;i<n;i++)
    {
        prefix += (a[i] - a[i-1])*(i - n/2);
        if(prefix > k)
        {
            prefix -= (a[i] - a[i-1])*(i - n/2);
            break;
        }
        md = a[i];
    }
    i -= n/2;
    k -= prefix;
    md += (k/i);
    cout<<md;
}