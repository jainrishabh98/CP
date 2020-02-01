#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        pair<long long, int> en[n + 1];
        int ans[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> en[i].first;
            en[i].second = i;
        }
        sort(en + 1, en + n + 1);
        int answ = 0;
        long long left = 0;
        int j = 0;
        en[0].first = 0;
        for (int i = 1; i <= n; i++)
        {
            left += en[i].first - en[i - 1].first;
            if (j >= i)
            {
                left += en[i].first - en[i - 1].first;
            }
            if (j == i)
                j--;
            while (true)
            {
                int store = j;
                j++;
                if (j == i)
                {
                    j++;
                }
                if (j > n)
                    break;
                if (left > en[j].first)
                {
                    left += k - en[j].first;
                    answ++;
                }
                else
                {
                    j = store;
                    break;
                }
            }
            ans[en[i].second] = answ;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}