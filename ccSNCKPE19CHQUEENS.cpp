#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        ll ans =0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(i==x && j==y)
                    continue;
                else
                {   ll temp = ((n*m) - (n+m + min(i-1,j-1) + min(n-i,m-j) + min(m-j,i-1) + min(n-i,j-1)));
                    
                    if(x==i)
                    {
                        if(y-j>0)
                            temp += (m-y) + 1;
                        
                        else
                            temp += (y-1) + 1;
                    }
                    else if(y==j)
                    {
                        if(x-i>0)
                            temp += (n-x) + 1;
                        else
                            temp += (x-1) + 1;
                    }
                    else if((abs(x-i)/(double)(abs(y-j)))==1) //diagonal
                    {
                        if(x-i>0 && y-j>0)
                            temp += min(n-x,m-y) + 1;
                        
                        else if(x-i>0 && y-j<0)
                            temp += min(n-x,y-1) + 1;
                        
                        else if(x-i<0 && y-j<0)
                            temp += min(x-1,y-1) + 1;
                        
                        else
                            temp += min(x-1,m-y) + 1;
                        
                    }
                    ans += temp;
                    //cout<<temp<<" ";
                }
            }
            //cout<<"\n";
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}