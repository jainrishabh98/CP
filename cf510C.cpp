#include <bits/stdc++.h>
using namespace std;
set<int> charset[26], cset[26];
int vis[26];
bool v[26],cv[26];int flag=0;
void dfs(int u)
{
    v[u] = true;
    cv[u] = true;
    for(auto j:charset[u])
    {
        if(!v[j])
        {
            dfs(j);
        }
        else if(cv[j]==true)
        {
            flag=1;
            return ;
        }
    }
    cv[u] = false;
}
int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    flag=0;
    for (int i = 1; i < n; i++)
    {
        if (s[i][0] != s[i - 1][0])
        {
            charset[s[i][0] - 'a'].insert(s[i - 1][0] - 'a');
        }
        else
        {
            int j = 0, k = min(s[i].length(), s[i - 1].length()), fl = 0;
            while (j < k)
            {
                if (s[i][j] != s[i - 1][j])
                {
                    charset[s[i][j] - 'a'].insert(s[i - 1][j] - 'a');
                    fl = 1;
                    break;
                }
                j++;
            }
            if (s[i].length() < s[i - 1].length() && fl == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        if(!v[i])
        {
            dfs(i);
            if(flag==1) break;
        }
    }
    if (flag == 1)
        cout << "Impossible";
    else
    {
        queue<int> msrc;
        for (int i = 0; i < 26; i++)
        {
            if (charset[i].empty())
            {
                msrc.push(i);
                vis[i] = 1;
            }
            else
            {
                for (auto j : charset[i])
                {
                    cset[j].insert(i);
                }
            }
        }
        while (!msrc.empty())
        {
            int u = msrc.front();
            msrc.pop();
            for (auto j : cset[u])
            {
                if (vis[j]<vis[u]+1)
                {
                    vis[j] = vis[u] + 1;
                    msrc.push(j);
                }
            }
        }
        set <pair<int,int> > ss;
        for(int i=0;i<26;i++)
        {
            ss.insert(make_pair(vis[i],i));
        }
        for(auto i:ss)
        {
            cout<<(char)(i.second+'a');
        }
    }
}