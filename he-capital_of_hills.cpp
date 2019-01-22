#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> s;
    // s.push(a[0]);
    long long int ans = 0, cnt = 0, cnt2 = 0;
    int lpop = 0, cn = 0, prevcn = 0, prevcnn = 0, cnn = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = lpop = cn = cnt2 = prevcn = 0;
        cnn = 1;
        while (a[i] == a[i + 1] && i < n - 1)
        {
            cnn++;
            i++;
        }
        if (!s.empty())
        {
            lpop = s.top();
            while (a[i] > s.top())
            {
                if (s.top() == lpop)
                    cn++;
                else
                {
                    lpop = s.top();
                    cnt += (prevcn * cn) + (cn * (cn - 1)) / 2;
                    prevcn = cn;
                    cn = 1;
                }
                cnt2++;
                s.pop();
                if (s.empty())
                    break;
            }
            cnt += (prevcn * cn) + (cn * (cn - 1)) / 2;
            prevcn = cn;
            cnt += (cnt2 * cnn);
        }
        if (!s.empty() && cnt != 0)
        {
            int x = s.top();
            prevcnn = 0;
            while (x == s.top())
            {
                prevcnn++;
                s.pop();
                if (s.empty())
                    break;
            }
            cnt += prevcn * prevcnn;
            while (prevcnn--)
                s.push(x);
        }
        while (cnn--)
            s.push(a[i]);

        ans += cnt;
    }
    // cout<<ans<<" ";
    cnt = lpop = cn = prevcn = 0;
    if (!s.empty())
        lpop = s.top();
    while (!s.empty())
    {
        if (s.top() == lpop)
            cn++;
        else
        {
            lpop = s.top();
            cnt += (prevcn * cn) + (cn * (cn - 1)) / 2;
            prevcn = cn;
            cn = 1;
        }
        // cout<<cnt<<" ";
        s.pop();
    }
    cnt += (prevcn * cn) + (cn * (cn - 1)) / 2;
    cout << ans + cnt << "\n";
}