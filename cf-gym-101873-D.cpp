#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<string, vector<string>> mp;
map<string, vector<string>> rmp;
map<string, int> v, rv;
string a, b;
int fl = 0;
void dfs(string u)
{
    v[u] = 1;
    if (u == b)
    {
        fl = 1;
        return;
    }
    for (auto i : mp[u])
    {
        if (v.find(i) == v.end())
        {
            dfs(i);
        }
    }
}
void rdfs(string u)
{
    rv[u] = 1;
    if (u == a)
    {
        fl = 1;
        return;
    }
    for (auto i : rmp[u])
    {
        if (rv.find(i) == rv.end())
        {
            rdfs(i);
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> s >> s >> s >> b;
        mp[a].push_back(b);
        rmp[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (mp.find(a) == mp.end() || rmp.find(b) == rmp.end())
        {
            cout << "Pants on fire\n";
            continue;
        }
        fl = 0;
        dfs(a);
        if(fl==1)
        {
            cout<< "Fact\n";
        }
        else
        {
            rdfs(b);
            if(fl==1)
            {
                cout<< "Alternative Fact\n";
            }
            else
            {
                cout << "Pants on fire\n";
            }
        }
    }
}