#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y,n,m,k;
        cin>>x>>y>>n>>m>>k;
        ld a[n],b[n];
        ld c[m],d[m];
        ld e[k],f[k];
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i];
        for(int i=0;i<m;i++)
            cin>>c[i]>>d[i];
        for(int i=0;i<k;i++)
            cin>>e[i]>>f[i];
        ld dist1[n];
        ld dist2[m];
        ld dist3[m];
        ld dist4[n];
        for(int i=0;i<m;i++)
        {
            ld temp = sqrt((c[i] - e[0])*(c[i]-e[0]) + (d[i]-f[0])*(d[i]-f[0]));
            for(int j=1;j<k;j++)
            {
                temp = min(temp,sqrt((c[i] - e[j])*(c[i]-e[j]) + (d[i]-f[j])*(d[i]-f[j])));
            }
            dist3[i] = temp;
        }
        for(int i=0;i<n;i++)
        {
            ld temp = sqrt((c[0] - a[i])*(c[0]-a[i]) + (d[0]-b[i])*(d[0]-b[i])) + dist3[0];
            for(int j=1;j<m;j++)
            {
                temp = min(temp,sqrt((c[j] - a[i])*(c[j]-a[i]) + (d[j]-b[i])*(d[j]-b[i])) + dist3[j]);
            }
            dist4[i] = temp;
        }


        for(int i=0;i<n;i++)
        {
            ld temp = sqrt((a[i] - e[0])*(a[i]-e[0]) + (b[i]-f[0])*(b[i]-f[0]));
            for(int j=1;j<k;j++)
            {
                temp = min(temp,sqrt((a[i] - e[j])*(a[i]-e[j]) + (b[i]-f[j])*(b[i]-f[j])));
            }
            dist1[i] = temp;
        }
        for(int i=0;i<m;i++)
        {
            ld temp = sqrt((c[i] - a[0])*(c[i]-a[0]) + (d[i]-b[0])*(d[i]-b[0])) + dist1[0];
            for(int j=1;j<n;j++)
            {
                temp = min(temp,sqrt((c[i] - a[j])*(c[i]-a[j]) + (d[i]-b[j])*(d[i]-b[j])) + dist1[j]);
            }
            dist2[i] = temp;
        }
        ld ans = 1e16;
        for(int i=0;i<n;i++)
        {
            ans = min(ans,dist4[i] + sqrt((a[i] - x)*(a[i]-x) + (b[i]-y)*(b[i]-y)));
        }
        for(int i=0;i<m;i++)
        {
            ans = min(ans,dist2[i] + sqrt((c[i] - x)*(c[i]-x) + (d[i]-y)*(d[i]-y)));
        }
        cout<<fixed;
        cout<<setprecision(10)<<ans<<"\n";
    }
}