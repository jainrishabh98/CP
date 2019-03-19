#include <bits/stdc++.h>
using namespace std;
struct st
{
    int a, b;
};
bool comp(st x, st y)
{
    return (x.a < y.a);
}
int main()
{
    int n;
    cin >> n;
    st s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].a >> s[i].b;
    }
    sort(s, s + n, comp);
    int ans = 0;
    int mx = s[0].b;
    for (int i = 1; i < n; i++)
    {
        if(s[i].b > mx)
        {
            mx = s[i].b;
        }
        else
            ans++;
    }
    cout << ans;
}