#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        map <long long , int> mp;
        queue<long long> q;
        q.push(n);
        mp[n] = 1;
        int fl=0;
        while(!q.empty())
        {
            long long p = q.front();
            q.pop();
            if(p==1)
            {
                fl=1;
                break;
            }
            if(p%10==0 && mp.find(p/10)==mp.end())
            {
                q.push(p/10);
            }
            if(p%20==0 && mp.find(p/20)==mp.end())
            {
                q.push(p/20);
            }
        }
        if(fl==1)
            cout<<"Yes\n";
        else
        {
            cout<<"No\n";
        }
        
        
    }
}