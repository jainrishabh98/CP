#include<bits/stdc++.h>
using namespace std;
int p2 [1001][1001] = {0};
int p5 [1001][1001] = {0};
int result[1001][1001][2][2];
int main ()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,ans=INT_MAX,tempr=ans,tempc=ans,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(x==0)
                {ans=1;tempr=i;tempc=j;}
            while(x%2==0 && x!=0)
            {
                p2[i][j]++;
                x/=2;
            }
            while(x%5==0 && x!=0) 
            {
                p5[i][j]++;
                x/=5;
            }
        }
    }
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=n;c++)
        {
            if(r==1 && c==1)
            {
                result[r][c][0][0] = p2[r][c]; // last state = 0 for value & 1 for direction
                result[r][c][0][1] = -1;
                result[r][c][1][0] = p5[r][c];
                result[r][c][1][1] = -1;
                
            }
            else if(r==1 && c!=1)
            {
                result[r][c][0][0] = p2[r][c] + result[r][c-1][0][0];
                result[r][c][0][1] = 0;
                result[r][c][1][0] = p5[r][c] + result[r][c-1][1][0];
                result[r][c][1][1] = 0;
                
            } 
            else if(r!=1 && c==1)
            {
                result[r][c][0][0] = p2[r][c] + result[r-1][c][0][0];
                result[r][c][0][1] = 1;
                result[r][c][1][0] = p5[r][c] + result[r-1][c][1][0];
                result[r][c][1][1] = 1;
                
            } 
            else
            {
                
                result[r][c][0][0] = p2[r][c] + min(result[r-1][c][0][0],result[r][c-1][0][0]);
                result[r][c][0][1] = (result[r-1][c][0][0] < result[r][c-1][0][0]) ? 1 : 0;
                result[r][c][1][0] = p5[r][c] + min(result[r-1][c][1][0],result[r][c-1][1][0]);
                result[r][c][1][1] = (result[r-1][c][1][0] < result[r][c-1][1][0]) ? 1 : 0;

            }
           

        }
    }
    // cout<<result[n][n][0][0]<<" "<<result[n][n][1][0]<<"\n";
    int ans2 = min(result[n][n][0][0],result[n][n][1][0]);
    if(ans2 < ans)
    {
        cout<<ans2<<"\n"; // no. of trailing zeroes

    int p = (result[n][n][0][0] < result[n][n][1][0]) ? 0 : 1;
    stack <char> s;
        int r=n,c=n;
        while(result[r][c][p][1] != -1)
        {
            //  cout<<result[r][c][p][1]<<"\n";
            if(result[r][c][p][1] == 1)
               { r=r-1; s.push('D'); }
            else
               { c=c-1; s.push('R'); }
        }
    while(!s.empty())
        {cout<<s.top();
        s.pop();
        }
    }
    else
    {
         cout<<"1\n";
         for(int i=1;i<tempr;i++)
            cout<<"D";
        for(int i=1;i<n;i++)
            cout<<"R";
        for(int i=tempr;i<n;i++)
            cout<<"D";
    }
    cout<<"\n";
    return 0;
}