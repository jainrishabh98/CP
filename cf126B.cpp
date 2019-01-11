#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int len = 0;
    int low = 0, high = l - 1;
    string ans;
    int flag = 0;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (s.substr(0, mid) == s.substr(l - mid, mid))
        {
            string t = s.substr(mid, l - 2 * mid);
            int index = t.find(s.substr(0, mid));
            cout << t << "\n";
            if (index < l)
            {
                ans = s.substr(0, mid);
                flag = 1;
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
            high = mid - 1;
    }
    if (flag == 0)
        cout << "Just a legend\n";
    else
        cout << ans << "\n";

    return 0;
}