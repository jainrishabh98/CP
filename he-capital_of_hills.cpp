#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    stack <int> s;
    s.push(a[0]);
    int cnt=0;long long int ans=0;int lpop=0,cn=0;
    for(int i=1;i<n;i++)
    {   cnt=0;lpop=0;cn=0;
        if(!s.empty())
        {
        while(a[i]>s.top())
        {  
            if(s.top()==lpop) cn++;
            else lpop = s.top();
            cnt++;
            s.pop();
            if(s.empty())   break;
        }
        }
        if(!s.empty() && cnt!=0) ans++;
        s.push(a[i]);
        ans += max(0,cnt + cnt -1);
    }
    int l = s.size();
    ans += l-1;
    cout<<ans<<"\n";
}