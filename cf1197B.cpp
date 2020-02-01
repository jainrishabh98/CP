#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    cin >> n;
    pair<ll, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a+n);
    int l = a[n-1].second,r=l;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i].second - r==1)
        {
            r = a[i].second;
        }
        else if(l - a[i].second == 1)
        {
            l = a[i].second;
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}