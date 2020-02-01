#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt[101] = {0};
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            cnt[x]++;
        }
        int ans = n;
        for(int i=1;i<=100;i++)
        {
            ans = min(ans,n-cnt[i]);
        }
        cout<<ans<<"\n";
    }
}