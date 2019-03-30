#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> g[100005];
int main()
{
    int n;
    cin >> n;
    int c[n];
    int p, root;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> c[i];
        if (p != -1)
            g[p].push_back(i + 1);
        else
            root = i + 1;
    }
    set <int> dell;
    for (int i = 1; i <= n; i++)
    {
        if (c[i - 1] == 1)
        {
            int flag = 0;
            for (auto j : g[i])
            {
                if (c[j - 1] == 0)
                    flag = 1;
            }
            if(flag==0)
            {
                dell.insert(i);
            }
        }
    }
    if(dell.empty())
    {
        cout<<-1;
        return 0;
    }
    for(auto k:dell)
    {
        cout<<k<<" ";
    }
}