#include <bits/stdc++.h>
using namespace std;
int prefx[1005][1005];
int prefy[1005][1005];
vector<pair<int, int>> v;
vector<pair<char, int>> ins;
char c[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
            {
                prefx[i][j]++;
            }
            else if (c[i][j] != '.')
            {
                v.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[j][i] == '#')
            {
                prefy[j][i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            prefx[i][j] += prefx[i][j - 1];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            prefy[j][i] += prefy[j - 1][i];
        }
    }
    int k;
    cin >> k;
    char a;
    int kk;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> kk;
        ins.push_back({a, kk});
    }
    string ans;
    for (auto p : v)
    {
        int x = p.first;
        int y = p.second;
        int flag = 0;
        for (auto pp : ins)
        {
            a = pp.first;
            kk = pp.second;
            if (a == 'W' && prefx[x][y - kk - 1] == prefx[x][y] && y - kk >= 1)
                y -= kk;

            else if (a == 'E' && prefx[x][y + kk] == prefx[x][y] && y + kk < m - 1)
                y += kk;

            else if (a == 'N' && prefy[x - kk - 1][y] == prefy[x][y] && x - kk >= 1) 
                x -= kk;

            else if (a == 'S' && prefy[x + kk][y] == prefy[x][y] && x + kk < n - 1)
                x += kk;

            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ans.push_back(c[p.first][p.second]);
        }
    }
    if (ans.size() == 0)
    {
        cout << "no solution";
        return 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans;
}