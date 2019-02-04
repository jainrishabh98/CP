#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    int mx = 0;
    vector <int> v;
    v.push_back(p-1);
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {   
            if(i!=p-1 && n-i!=p)
            {
            if(p<n/2)
                v.push_back(i);
            else
                v.push_back(n-i-1);
            }
            mx += min(abs(s[i]-s[n-i-1]),26 - abs(s[i]-s[n-i-1]));
        }
    }
    sort(v.begin(),v.end());
    int ind = lower_bound(v.begin(),v.end(),p-1) - v.begin();
    // cout<<mx<<" ";
    // cout<<v[0]<<" "<<v[ind]<<" "<<v[v.size()-1]<<"\n";
    if(v[ind]-v[0] >= v[v.size()-1]-v[ind])
    {   
        mx += (2*(v[v.size()-1]-v[ind]) + v[ind]-v[0]);
    }
    else
    {
        mx += (2*(v[ind]-v[0]) + v[v.size()-1]-v[ind]) ;
    }
    cout<<mx;
}