#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int cnt[1000001]={0};
int main ()
{
    int n;
    cin>>n;
    int x;
    for(int i=0;i<3*n;i++)
       { cin>>x;
        cnt[x]++;
       }
    int ans = 0;
    for(int i=0;i<1000001;i++)
    {
        if(cnt[i]==3) ans++;
    }
    cout<<ans<<"\n";

}