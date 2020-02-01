#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll anss = 0;
        ll c,x;
        cin>>c>>x;
        if(x==1 || x>c)
        {
            cout<<c<<"\n";
            continue;
        }
        while(c!=0)
        {
            anss += c%x;
            c -= c%x;
            c /= x;
        }
        cout<<anss<<"\n";
    }
}