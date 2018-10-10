#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll ;
vector <ll> v;
double dist (double a, double b, double x, double y)
{
    double v1 = (x-a)*(x-a);
    double v2 = (y-b)*(y-b);
    double ans = sqrt(v1+v2);
    return ans;
}
int main ()
{
    ll n,q;
    cin>>n>>q;
    double x[n],y[n],r[n];
    for (ll i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    v.assign(1000002,0);
    for(ll i = 0; i<n; i++)
    {
        for ( ll j = i+1; j<n;j++)
        {
            double temp = dist(x[i],y[i],x[j],y[j]);
            ll mx=0,mn=0;
            if (temp==0 && r[i]==r[j])
            {
                mx = 0;
                mn = 0;
            }
            else if(temp>=(r[i]+r[j]))
            {
                mx = floor(temp + r[i] + r[j]);
                mn = ceil(temp - r[i] - r[j]);
            }
            else if (temp<abs(r[i]-r[j]))
            {
                
                mn = ceil(max(r[i],r[j]) - temp - min(r[i],r[j]));
                mx = floor(temp + r[i] + r[j]);
            }
            else
            {
                mx = floor(temp + r[i] + r[j]);
                mn = 0; 
            }

            v[mn]++;
            v[mx+1]--;
        }
    }
    for(int i = 1; i<v.size(); i++)
    {
        v[i] = v[i] + v[i-1];
    }

    while(q--)
    {
        ll k;
        cin>>k;
        cout<<v[k]<<"\n";
    }
    return 0;
}