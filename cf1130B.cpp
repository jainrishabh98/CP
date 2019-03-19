#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    pair<int,int> s[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>s[i].first;
        s[i].second = i+1;
    }
    sort(s,s+2*n);
    long long int ans = 0;
    ans += s[0].second + s[1].second - 2;
    int x = s[0].second;
    int y = s[1].second;
    for(int i=2;i<2*n;i+=2)
    {   
        
        if(abs(s[i].second - x) + abs(s[i+1].second - y) > abs(s[i].second - y) + abs(s[i+1].second - x))
        {
            ans += abs(s[i].second - y) + abs(s[i+1].second - x);
            x = s[i+1].second;
            y = s[i].second;
        }
        else
        {
            ans += abs(s[i].second - x) + abs(s[i+1].second - y);
            y = s[i+1].second;
            x = s[i].second;
        }
        
    }
    cout<<ans;
}