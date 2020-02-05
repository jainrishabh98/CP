#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<double, double> dp[51][22];
double cost[51];
double val[51];
int n;
double m;
double ans = 0.0;
double vv = -1.0;
vector <int> a;
double rec(int i, int d, double ml,vector<int> v,double vvv)
{
    if(d==0)
    {
        if(vvv > ans)
        {
            a.clear();
            a = v;
            ans = vvv;
            vv = m - ml;
        }
        else if(vvv == ans && m-ml < vv)
        {
            a.clear();
            a = v;
            vv = m - ml;
        }
        return 0.0;
    }
    if(i == n+1)
        return 0.0;
    if(dp[i][d].find(ml)!=dp[i][d].end())
        return dp[i][d][ml];
    dp[i][d][ml] = 0.0;
    if(ml >= cost[i] && d>=1)
    {
        v.push_back(i);
        dp[i][d][ml] = max(dp[i][d][ml],val[i]+rec(i+1,d-1,ml-cost[i],v,vvv+val[i]));
    }
    if(ml >= 2*cost[i] && d>=2)
    {
        v.push_back(i);
        v.push_back(i);
        dp[i][d][ml] = max(dp[i][d][ml],1.5*val[i] + rec(i+1,d-2,ml-2*cost[i],v,vvv+1.5*val[i]));
    }
    dp[i][d][ml] = max(dp[i][d][ml],rec(i+1,d,ml,v,vvv));
    return dp[i][d][ml];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    while (true)
    {
        cin >> k >> n >> m;
        if (k + n + m == 0)
            break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j].clear();
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i]>>val[i];
        }
        ans = 0.0;
        vv = -1.0;
        a.clear();
        vector<int> v;
        rec(1,k,m,v,0.0);
        cout<<ans<<"\n";
        for(auto i:a)
            cout<<i<<" ";
        cout<<"\n";
    }
}