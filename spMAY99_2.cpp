#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        // ll m=n;
        char a[] = {'m','a','n','k','u'};
        ll cnt = 1;
        ll temp = 5;
        while(n-temp > 0)
        {
            n = n - temp;
            cnt++;
            temp = temp*5;
        }
        int b[cnt] = {0};
        ll tmp = cnt;
        while(cnt!=0)
        {
        temp /= 5;
        cnt--;
        while(n-temp > 0)
        {
            b[cnt]++;
            n = n-temp;
        }
        }
        for(int i=tmp-1;i>=0;i--)
        {
            cout<<a[b[i]];
        }
        cout<<"\n";
        // cout<<n<<"\n";
    }
    return 0;
}