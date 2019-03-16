#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],last[100005];
int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int ans = 0;
        for (int j = 1; j * j <= x[i]; ++j)
        {
            if (x[i] % j == 0)
            {
                if (j == x[i] / j)
                {
                    if (last[j] < i - y[i])
                        ++ans;
                    last[j] = i;
                }
                else
                {
                    if (last[j] < i - y[i])
                        ++ans;
                    last[j] = i;
                    if (last[x[i] / j] < i - y[i])
                        ++ans;
                    last[x[i] / j] = i;
                }
            }
        }
        cout << ans << endl;
    }
}