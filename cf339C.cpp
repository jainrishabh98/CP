#include <bits/stdc++.h>
using namespace std;
vector<int> weights, ans;
int m, prv = 0, balance[2] = {0}, step = 0;
void dfs(int x)
{
    if (step == m)
    {
        cout << "YES\n";
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        exit(0);
    }

    for (auto i : weights)
    {
        if (i != prv && balance[x] + i > balance[x ^ 1])
        {
            balance[x] += i;
            ans.push_back(i);
            prv = i;
            step++;
            dfs(x ^ 1);
            step--;
            balance[x] -= i;
            ans.pop_back();
            prv = 0;
            if (step != 0)
                prv = ans[step - 1];
        }
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    cin >> s;
    cin >> m;
    for (int i = 0; i < 10; i++)
    {
        if (s[i] == '1')
        {
            weights.push_back(i + 1);
        }
    }
    dfs(0);
    cout << "NO";
}