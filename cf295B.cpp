#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>adj[i][j];
    }
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    vector <int> incl;
    vector <long long int> ans;
    ans.push_back(0);
    incl.push_back(x[n-1]);
    long long int sum=0;
    for(int i=n-2;i>=0;i--)
    {   int inter = x[i];
        sum=0;
        // update distance of x[i] using vertices already present as intermediate in O(n2)
        for(auto j:incl)
        {
            for(auto k:incl)
            {
                adj[inter][k] = min(adj[inter][k],adj[inter][j]+adj[j][k]);
                adj[k][inter] = min(adj[k][inter],adj[k][j]+adj[j][inter]);
            }
        }
        // update distances of already present vertices using x[i] as intermediate in O(n2)
        for(auto j:incl)
        {
            for(auto k:incl)
            {
                adj[j][k] = min(adj[j][k],adj[j][inter]+adj[inter][k]);
            }
        }
        
        incl.push_back(inter);
        for(auto j:incl)
        {
            for(auto k:incl)
            {
                sum += adj[j][k];
            }
        }
        ans.push_back(sum);
    }
    auto i = ans.end();i--;
    while(i>=ans.begin())
    {
        cout<<*i<<" ";
        i--;
    }
    cout<<"\n";
    return 0;
}