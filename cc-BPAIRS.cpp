#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
    ll l1, r1, l2, r2, id;
};
bool comp(st x, st y)
{
    return (x.r1 < y.r1);
}
bool comp2(st x, st y)
{
    return(x.id < y.id);
}
ll bit[100005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pair<ll, ll> p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    int q;
    cin >> q;
    st s[q];
    for (int i = 0; i < q; i++)
    {
        cin >> s[i].l1 >> s[i].r1 >> s[i].l2 >> s[i].r2;
        s[i].id = i;
    }
}