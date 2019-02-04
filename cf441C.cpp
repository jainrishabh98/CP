#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x = 1, y = 1, fl = 1, flag = 1;
    vector <pair<int,int> > v;
    for(int i=1;i<=n;i++)
    {   
        if(i%2!=0)
        {
        for(int j=1;j<=m;j++)
        {
            v.push_back(make_pair(i,j));
        }
        }
        else
        {
        for(int j=m;j>=1;j--)
        {
            v.push_back(make_pair(i,j));
        }
        }
    }
    for(int i=0;i<2*(k-1);i+=2)
    {
        cout<<"2 "<<v[i].first<<" "<<v[i].second<<" "<<v[i+1].first<<" "<<v[i+1].second<<"\n";
    }
    cout<<v.size()-(2*(k-1))<<" ";
    for(int i=2*(k-1);i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<" ";
    }
}