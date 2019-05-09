#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    double x[n],y[n];
    int leader[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        leader[i] = i;
    }
    double slope;
    map <double,long long int> mp;
    map<pair<double,int>,int> mpp;
    long long int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            
            if(x[j]==x[i])
            {
                slope = 100000000;
            }
            else
            {
                slope = (y[j]-y[i])/(x[j]-x[i]);
            }
            if(mpp.find({slope,i+1})!=mpp.end())
            {
                mpp[{slope,j+1}] = 1;
            }
            else
            {
                mpp[{slope,i+1}] = 1;
                mpp[{slope,j+1}] = 1;
                mp[slope]++;
                cnt++;
            }
        }
        // cout<<cnt<<" ";
    }
    long long ans = 0;
    for(auto k:mp)
    {
        ans += ((cnt - k.second)*k.second);
    }
    cout<<ans/2;
}