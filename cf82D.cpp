#include<bits/stdc++.h>
using namespace std;
struct st{
    int num;
    int val;
};
int dp[501][2][2];
int main ()
{
    int n;
    st p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].val;
        p[i].num = i+1;
    }
    int temp = ceil(n/2.0);
    for(int i=1;i<=temp;i++)
    {
        if(i==1)
        {
           // dp[i][0][0] = 2nd largest time
           // dp[i][0][1] = 3
           // dp[i][1][0] = largest time
           // dp[i][1][1] = 1
        }
        else if (i==temp)
        {
            if(temp%2==0)
                dp[i][0][0] = 
        }
        else
        {
            if()
        }
    }
    return 0;
}