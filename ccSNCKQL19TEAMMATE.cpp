#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
ll precal[100001];
void prefac()
{   ll f=1;
    precal[0]=1;
    precal[1]=1;
    for(int i=2;i<100001;i++)
    {
        f=(f*i)%m;
        precal[i]=f;
    }
}
ll fastpower(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = fastpower(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

// struct st{
//     ll val;
//     ll cnt;
// };
int main ()
{
    int t,n;
    prefac();
    cin>>t;
    while(t--)
    {
        cin>>n;
        // vector <st> s;
        vector <ll> c;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int i=0;
        while(i<n)
        {   int p = i+1;
            int cn =1;
            while(a[p]==a[i] && p<n)
            {
                cn++;
                p++;
            }
            c.push_back(cn);
            i=p;
        }
        ll temp,ans=1,left=0;
        
        for(int i=c.size()-1;i>=0;i--)
        {
            //cout<<s[i].val<<" "<<s[i].cnt<<"\n";
            if(left!=0)
               { ans = (ans*left*c[i])%m;
                c[i] = c[i] - left;
               }
            if(c[i]>2)
                {
                    ll a = precal[c[i]];
                    ll k = c[i]/2;
                    ll b = precal[k];
                    ll c = fastpower(2,k);
                    ll inv = ((b%m)*(c%m))%m;
                    inv = fastpower(inv,m-2);
                    temp = ((a%m)*(inv%m))%m;
                }
            else
                temp=1;
            left = c[i]%2;
            ans = (ans*temp)%m;
            
        }
        cout<<ans<<"\n";
    }

}