#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    int t[k+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>x;
        t[x]++;
    }
    sort(t+1,t+k+1);
    int ans = INT_MAX;
    int i,j,cnt;
    for(int s=t[k];s<=n;s++)
    {
        i=1;j=k;cnt=0;
        while(i < j)
        {
            while(t[j] + t[i] > s && j > i)
            {
                j--;
            }
            if(j <= i) break;
            cnt++;
            i++;
            j--;
        }
        if(ans > s*(k-cnt))
            ans = s*(k-cnt);
    }
    cout<<ans;
}