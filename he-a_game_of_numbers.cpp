#include<bits/stdc++.h>
using namespace std;
long long int a[30005];
int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int f[n];
    int g[n];
    stack <int> s;
    for(int i=0;i<n;i++)
    {
        if(!s.empty())
        {
            while(a[s.top()] < a[i])
            {
                f[s.top()] = i;
                s.pop();
                if(s.empty())
                    break;
            }
        }
        s.push(i);
    }
    while(!s.empty())
    {
        f[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        if(!s.empty())
        {
            while(a[s.top()] > a[i])
            {
                g[s.top()] = i;
                s.pop();
                if(s.empty())
                    break;
            }
        }
        s.push(i);
    }
    while(!s.empty())
    {
        g[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        if(f[i]==-1 || g[f[i]]==-1)
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<a[g[f[i]]]<<" ";
        }
    }
}