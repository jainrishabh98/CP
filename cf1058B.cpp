#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,m;
    cin>>n>>d>>m;
    int x[m],y[m];
    for (int i = 0; i < m; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<m;i++)
    {   int a = x[i] + y[i];
        int b = y[i] - x[i];
        if((a - d)>=0 &&  a - (2*n -d)<=0 && b+d>=0 && b-d<=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}