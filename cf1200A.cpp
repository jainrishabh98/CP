#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int,int> mp;
    for(int i=0;i<=9;i++)
    {
        mp[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            for(int j=0;j<=9;j++)
            {
                if(mp.find(j)!=mp.end())
                {
                    mp.erase(j);
                    break;
                }
            }
        }
        else if(s[i]=='R')
        {
            for(int j=9;j>=0;j--)
            {
                if(mp.find(j)!=mp.end())
                {
                    mp.erase(j);
                    break;
                }
            }
        }
        else
        {
            int x = s[i]-'0';
            mp[x] = 1;
        }
    }
    for(int i=0;i<=9;i++)
    {
        if(mp.find(i)==mp.end())
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        
    }
}