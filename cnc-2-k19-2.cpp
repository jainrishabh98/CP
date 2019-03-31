#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x;
        cin >> m >> n;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            pq.push({x,{x,1}});
        }
        m -= n;
        int a,b,c;
        while (m != 0)
        {
            a = pq.top().first;
            b = pq.top().second.first;
            c = pq.top().second.second;
            pq.pop();
            c++;
            a = ceil(b/(float)(c));
            pq.push({a,{b,c}});
            m--;
        }
        cout<<pq.top().first<<"\n";
    }
}