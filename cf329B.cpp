#include <bits/stdc++.h>
using namespace std;
char mt[1005][1005];
#define mp make_pair
queue<pair<int, int>> q;
int vis[1005][1005];
int main()
{
    int r, c;
    cin >> r >> c;
    int sr, sc, m = 1e9;
    for (int i = 0; i <= r + 1; i++)
    {
        for (int j = 0; j <= c + 1; j++)
        {
            if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
            {
                mt[i][j] = 'T';
            }
            else
            {
                cin >> mt[i][j];
                if (mt[i][j] == 'E')
                {
                    sr = i;
                    sc = j;
                }
            }
            vis[i][j] = m;
        }
        // cin >> x;
    }
    q.push(mp(sr, sc));
    vis[sr][sc] = 1;
    int anr;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int t = vis[x][y];
        if (mt[x][y] == 'S')
        {
            anr = t;
        }
        if (vis[x - 1][y] == m && mt[x - 1][y] != 'T')
        {
            vis[x - 1][y] = t + 1;
            q.push(mp(x - 1, y));
        }
        if (vis[x + 1][y] == m && mt[x + 1][y] != 'T')
        {
            vis[x + 1][y] = t + 1;
            q.push(mp(x + 1, y));
        }
        if (vis[x][y - 1] == m && mt[x][y - 1] != 'T')
        {
            vis[x][y - 1] = t + 1;
            q.push(mp(x, y - 1));
        }
        if (vis[x][y + 1] == m && mt[x][y + 1] != 'T')
        {
            vis[x][y + 1] = t + 1;
            q.push(mp(x, y + 1));
        }
    }
    int ans = 0;
    for (int i = 1; i < r + 1; i++)
    {
        for (int j = 1; j < c + 1; j++)
        {
            if (mt[i][j] >= '0' && mt[i][j] <= '9')
            {
                if (vis[i][j] <= anr)
                {
                    ans += mt[i][j] - '0';
                }
            }
        }
    }
    cout << ans;
}