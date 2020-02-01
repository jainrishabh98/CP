#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a,a+n);
    double ans = 0;
    ans += (n-1)*a[0].first;
    for(int i=1;i<n-1;i++)
    {
        
    }
}