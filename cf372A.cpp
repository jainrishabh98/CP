#include<bits/stdc++.h>
using namespace std;
int main ()
{
     int n,temp;
    cin>>n;
     int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    deque <int> q;
    q.push_back(a[n-1]);
    int cnt=0;
    for(int i=n-2;i>=0;i--)
    {   
        if(!q.empty())
        {
        if(q.front() >= 2*a[i])
        {
            cnt++;
            q.pop_front();
        }
        else
        {
            q.push_back(a[i]);
        }
        }
        else
        {
            q.push_back(a[i]);
        }
    }
    while(!q.empty()) q.pop_back();
    int ans = n - cnt;cnt=0;
    q.push_back(a[0]);
    for(int i=1;i<n;i++)
    {   
        if(!q.empty())
        {
        if(a[i] >= 2*q.front())
        {
            cnt++;
            q.pop_front();
        }
        else
        {
            q.push_back(a[i]);
        }
        }
        else
        {
            q.push_back(a[i]);
        }
    }
    cout<<min(ans,n-cnt);
}