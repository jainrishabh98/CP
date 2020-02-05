#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int fl1=0,fl2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
                fl1=1;
            else
                fl2=1;
        }
        if(fl2 == 0)
        {
            cout<<"NO\n";
        }
        else if(fl1 == 0)
        {
            if(n%2==0)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            
        }
        else
        {
            cout<<"YES\n";
        }
    }
}