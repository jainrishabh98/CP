#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    double ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += ((double)(1))/((double)(i));
    }
    cout<<fixed;
    cout<<setprecision(5)<<ans;
}