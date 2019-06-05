#include <bits/stdc++.h>
using namespace std;
int a[1501][1501];
pair<int, int> vis[1501][1501];
int n, m;
int M = 1e5;
void dfs(int x, int y)
{
    if (vis[(x + n*n) % n][(y + m*m) % m].first == M && vis[(x + n*n) % n][(y + m*m) % m].second == M)
    {
        vis[(x + n*n) % n][(y + m*m) % m].first = x;
        vis[(x + n*n) % n][(y + m*m) % m].second = y;
    }
    else
    {
        // cout<<x<<" "<<y<<"\n";
        cout<<"Yes";
        exit(0);
    }
    // cout<<x<<" "<<y<<"\n";
    if ((vis[(x + 1 + n*n) % n][(y + m*m) % m].first != x + 1 || vis[(x + 1 + n*n) % n][(y + m*m) % m].second != y) && a[(x + 1 + n*n) % n][(y + m*m) % m] == 0)
    {
        dfs((x + 1), y);
    }
    if ((vis[(x - 1 + n*n) % n][(y + m*m) % m].first != x - 1 || vis[(x - 1 + n*n) % n][(y + m*m) % m].second != y) && a[(x - 1 + n*n) % n][(y + m*m) % m] == 0)
    {
        dfs((x - 1), y);
    }
    if ((vis[(x + n*n) % n][(y + 1 + m*m) % m].first != x || vis[(x + n*n) % n][(y + 1 + m*m) % m].second != y + 1) && a[(x + n*n) % n][(y + 1 + m*m) % m] == 0)
    {
        dfs(x, (y + 1));
    }
    if ((vis[(x + n*n) % n][(y - 1 + m*m) % m].first != x || vis[(x + n*n) % n][(y - 1 + m*m) % m].second != y - 1) && a[(x + n*n) % n][(y - 1 + m*m) % m] == 0)
    {
        dfs(x, (y - 1));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int rx, ry;
    char x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x == '.')
            {
                a[i][j] = 0;
            }
            else if (x == 'S')
            {
                a[i][j] = 0;
                rx = i;
                ry = j;
            }
            else
            {
                a[i][j] = 1;
            }
            vis[i][j].first = M;
            vis[i][j].second = M;
        }
    }
    dfs(rx, ry);
    cout<<"No";
}