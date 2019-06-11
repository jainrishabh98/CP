#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n, k;
    cin >> n >> k;
    ll b;
    cin >> b;
    pair<ll, int> a[n-1];
    int x;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    cin>>x;
    sort(a,a+n-1);
    reverse(a,a+n-1);
    ll sum = 0;
    int best = n;
    for(int i=0;i<k;i++)
    {
        best = min(best,a[i].second);
        sum += a[i].first;
    }
    if(sum <= b)
    {
        cout<<n;
        return 0;
    }
    sum -= a[k-1].first;
    for(int i=k;i<n-1;i++)
    {
        if(a[i].second < best && sum+a[i].first > b)
        {
            best = a[i].second;
        }
    }
    cout<<best;
}