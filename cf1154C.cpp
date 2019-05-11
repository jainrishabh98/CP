#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    vector<int> idx({0, 1, 2, 0, 2, 1, 0});
    long long int weeks = min(a[0]/3, min(a[1]/2, a[2]/2));
    long long int ans = 0;
    a[0] -= weeks * 3;
    a[1] -= weeks * 2;
    a[2] -= weeks * 2;
    for (int start = 0; start < 7; ++start)
    {
        int day = start;
        vector<int> b = a;
        int cur = 0;
        while (b[idx[day]] > 0)
        {
            b[idx[day]]--;
            day = (day + 1) % 7;
            cur++;
        }
        ans = max(ans, weeks * 7 + cur);
    }
    cout << ans;
}