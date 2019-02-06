#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    set <int> a;
    int x;
    // int cnt[101]={0};
    for(int i=0;i<n;i++)
    {   cin>>x;
        a.insert(x);
    }
    int ans = 0;
    while(!a.empty())
    {   auto i = a.end();i--;
        while(i!=a.begin())
        {   
            
            
        }
    }
    cout<<ans;
}