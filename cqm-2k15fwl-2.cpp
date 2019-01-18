#include <bits/stdc++.h>
using namespace std;
vector <bool> v;
vector<vector<int>> g;
int val[100001];
struct st{
    int cnt=-1;
    int num=-1;
};
bool comp(st a,st b)
{
    return (a.cnt==b.cnt) ? (a.num > b.num) : (a.cnt>b.cnt);
}
st c[100001];
vector <int> common;
void edge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}
int my_dfs(int u)
{
    v[u] = true;
    // vector<int> temp;
    int t;
    for (auto j = g[u].begin(); j != g[u].end(); j++)
    {
        if(!v[*j])
        {
        // vector<int> t;
        t = my_dfs(*j);
        // temp.insert(temp.end(), t.begin(), t.end());
        if (__gcd(val[u], __gcd(val[1], val[t])) == 1 && u!=1)
                c[t].cnt++;
        }
    }
    if (g[u].size()==1 && u!=1)
    {
        c[u].num = u;
        c[u].cnt = 0;
        // vector<int> tmp;
        // tmp.push_back(u);
        // return tmp;
        return u;
    }
    return t;
    // else
    // {   if(u!=1)
    //     {
    //     for (auto i : temp)
    //     {
    //         if (__gcd(val[u], __gcd(val[1], val[i])) == 1)
    //             c[i].cnt++;
    //     }
    //     }
    //     return temp;
    // }
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e;
    cin >> n;
    e = n - 1;
    v.assign(n+1,false);
    g.assign(n+1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    int a, b;
    for (int i = 1; i <= e; i++)
    {
        cin >> a >> b;
        edge(a , b );
    }
    my_dfs(1);
    sort(c+1,c+n+1,comp);
    for(int i=1;i<=n;i++)
    {   
        if(c[i].num!=-1)
            cout<<c[i].num<<" ";
    }
    cout<<"\n";
}