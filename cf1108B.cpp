#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin>>n;
    vector <int> d;
    for(int i=0;i<n;i++)    {cin>>x;d.push_back(x);}
    sort(d.begin(),d.end());
    y = d[n-1];
    vector <int> v;
    for(int i=1;i<=y;i++)
    {
        if(y%i==0)
            v.push_back(i);
    }
    for(auto i:v)
    {   
        for(int j=0;j<d.size();j++)
        {
            if(d[j]==i)
            {
                d[j]=-1;
                break;
            }
        }
    }
    sort(d.begin(),d.end());
    cout<<d[n-1]<<" "<<y;
}