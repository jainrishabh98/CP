#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    long long int ans = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=1;j<m-1;j++)
            {
                if(a[i][j]=='*')
                {
                    if(a[i+1][j]=='*' && a[i+2][j]=='*' && a[i+1][j-1]=='*' && a[i+1][j+1]=='*')
                        ans++;
                }
            }
    }
    cout<<ans<<"\n";
    return 0;
}