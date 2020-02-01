#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<int,int> mp;
int main ()
{
    int n,k,p;
    cin>>n>>k;
    string s;
    for(int i=1;i<=k;i++)
    {
        cin>>s;
        if(s[2]=='O')
        {
            mp.clear();
        }
        else
        {
           cin>>p;
           if(mp.find(p)==mp.end())
           {
               mp[p] = 1;
           } 
           else
           {
               mp.erase(p);
           }
           
        }
        cout<<mp.size()<<"\n";
    }
}