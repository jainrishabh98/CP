#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, l, bb, h;
        cin >> a >> b >> c >> l >> bb >> h;
        int sum = 0;
        if ((a <= l && b <= bb && c <= h) )
        {
            sum += 4;
        }
        if ((b <= l && c <= bb && a <= h) )
        {
            sum += 4;
        }
        if ((a <= l && c <= bb && b <= h) )
        {
            sum += 4;
        }
        if ( (a <= bb && b <= l && c <= h))
        {
            sum += 4;
        }
        if ( (b <= bb && c <= l && a <= h))
        {
            sum += 4;
        }
        if ( (a <= bb && c <= l && b <= h))
        {
            sum += 4;
        }
        cout << sum << "\n";
    }
}