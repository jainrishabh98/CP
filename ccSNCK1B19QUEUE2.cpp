#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main ()
{
    ll t,n,m,k,l;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>l;
        ll a[n],presum[m];
        ll temp;
        map <ll,ll> c;
        map <ll,ll> d;
        ll i;
        for(i=0;i<m;i++)
            presum[i] = 0;
        for(i=0;i<n;i++)
            {cin>>a[i];
            temp = ceil(a[i]/(float)(l));
            d[temp] = a[i];
            if(temp<m)
                presum[temp]++;
            }
        c[0] = m + presum[0];
        for(i=1;i<m;i++)
            {   presum[i] += presum[i-1];
                c[i] = (m-i) + presum[i];
            }
        sort(a,a+n);
        for(i=0;i<n;i++)
            {
            temp = ceil(a[i]/(float)(l));
            if(temp>=m)
            {
            if(c.find(temp) == c.end())
                {   auto tmp = c.end();
                    tmp--;
                    ll prev = tmp->first;
                    c[temp] = c[prev] - (temp - prev) + 1;
                }
            else
                {
                c[temp] = c[temp] + 1;
                }
            }
            }
        ll flag = 0;
        // cout<<"ok1";
        for(auto it = c.begin(); it!= c.end();it++)
        {
            auto tem = it;
            tem++;
            if(tem!=c.end())
            {
                if((((tem->first) - (it->first)) > 1) && (((it->first)*l) < (k-1)))
                    {flag=1;
                     break;
                    }
            }
        }
        // cout<<"ok2";
        auto tem2 = c.end() ;
        tem2--;
        if(((tem2->first)*l) < (k-1))
            flag=1;
        if(flag==1)
        {
            cout<<"0\n";
        }
        else
        { ll mn = c.begin()->second;
          ll st = c.begin()->first;
            for(auto it = c.begin(); it!= c.end();it++)
            { if(it->second < mn && (((it->first)*l) < k))
            {
                mn = it->second;
                st = it->first;
            }
            }
        
        // auto index = lower_bound(a,a+n,st*l) - a;
        ll ans = d[st] - st*l;
        cout<<(mn*l) - ans<<"\n";
        }
    }
return 0;
}