#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        b++;
        int cnt = 0;
        while(b!=0)
        {
            cnt++;
            b /= 10;
        }
        cnt--;
        cout<<a*cnt<<"\n";
    }
}