#include<bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>
int main ()
{
    int n,d;
    cin>>n>>d;
    int a[n],x[n],y[n];
    a[0]=a[n-1]=0;
    int dist[n];
    for(int i=1;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<n;i++)
    {
        dist[i] = 100000000;
    }
    priority_queue <ipair, vector <ipair> , greater <ipair> > pq;
    pq.push({0,0});
    dist[0] = 0;
    while(!pq.empty())
    {
        int u = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(v==n-1)
            break;
        for(int i=1;i<n;i++)
        {
            if(i==v) continue;
            int temp = abs(x[i]-x[v]) + abs(y[i]-y[v]);
            if(dist[i] > d*temp + u - a[v])
            {
                dist[i] = d*temp + u - a[v];
                pq.push({dist[i],i});
            }
        }
    }
    cout<<dist[n-1];
}