#include <bits/stdc++.h>
using namespace std;
string ans;
int vis[26];
string c;
int cnt, flag;
void dfs(char x)
{
    vis[x - 'a'] = 1;
    ans.push_back(x);
    if (ans.length() == c.length())
    {
        flag = 0;
        return ;
    }
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] != x && abs(c[i] - x) != 1 && vis[c[i] - 'a'] == 0 && flag==1)
        {
            dfs(c[i]);
        }
    }
    if(flag==1)
    {
    vis[x-'a']=0;
    ans.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;
        c.clear();
        ans.clear();
        sort(s.begin(), s.end());
        int a[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            if (a[s[i] - 'a'] == 0)
            {
                c.push_back(s[i]);
            }
            a[s[i] - 'a']++;
        }
        string t;
        flag = 1;
        for (int i = 0; i < c.length(); i++)
        {
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            dfs(c[i]);
            if (flag == 0)
                break;
        }
        for (int i = 0; i < ans.length(); i++)
        {
            while (a[ans[i] - 'a'] != 0)
            {
                t.push_back(ans[i]);
                a[ans[i] - 'a']--;
            }
        }
        if (flag == 0)
            cout << t << "\n";
        else
            cout << "No answer\n";
    }
}