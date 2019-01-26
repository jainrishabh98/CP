#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int vis[5201][5201];
int n;
int a[5201][5201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s;
    int temp;
    vector<int> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= n / 4; j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                temp = s[j] - (int)'0';
            }
            else
            {
                temp = s[j] - 55;
            }
            for (int k = (j)*4; k >= (j - 1) * 4 + 1; k--)
            {
                a[i][k] = temp % 2;
                temp /= 2;
            }
        }
        if (n % i == 0)
            f.push_back(i);
    }
    int ans,ans1=-1,ans2=-1;
    int cnt=1;
    int flag=0;
    for(int i=1;i<n;i++)
    {   
        for(int j=1;j<=n;j++)
        {
            if(a[i][j] != a[i+1][j]) {flag=1;break;}
        }
        if(flag==0)
        {
            cnt++;
        }
        else
        {
            flag=0;
            if(ans1==-1) ans1 = cnt;
            else ans1 = __gcd(ans1,cnt);
            cnt = 1;
        }
    }
    cnt=1;
    flag=0;
    for(int i=1;i<n;i++)
    {   
        for(int j=1;j<=n;j++)
        {
            if(a[j][i] != a[j][i+1]) {flag=1;break;}
        }
        if(flag==0)
        {
            cnt++;
        }
        else
        {
            flag=0;
            if(ans2==-1) ans2 = cnt;
            else ans2 = __gcd(ans2,cnt);
            cnt = 1;
        }
    }
    ans = __gcd(ans1,ans2);
    // cout<<ans<<" ";
    sort(f.begin(),f.end());
    auto pos = lower_bound(f.begin(),f.end(),ans) - f.begin();
    if(f[pos]>ans)  pos--;
    cout<<f[pos];
}