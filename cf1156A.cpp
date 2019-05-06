#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int flag = 0;
    a[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] * a[i + 1] == 6)
        {
            flag = 1;
            break;
        }
        else if (a[i]*a[i+1] == 3 )
            ans += 4;
        else if(a[i+1]==2 && a[i-1]==3)
            ans += 2;
        else 
            ans += 3;
    }
    if(flag==1)
        cout<<"Infinite";
    else
        cout<<"Finite\n"<<ans;
}