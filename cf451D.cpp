#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    string s;
    cin>>s;
    ll n= s.length();
    ll ce = 0;
    ll co = 0;
    ll fla=0,flb=0,preva,prevb,prevcea=0,prevcoa=0,prevceb=0,prevcob=0,te,to;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='a' && fla==0) {fla=1;preva=i;}
        else if(s[i]=='b' && flb==0) {flb=1;prevb=i;}
        else if(s[i]=='a')
        {
            if((i-preva+1)%2==0)
            {   te = prevcoa + 1;
                to = prevcea;
                ce += te;
                co += to;
                prevcoa = to;
                prevcea = te;
            }
            else
            {
                te = prevcea;
                to = prevcoa+1;
                ce += te;
                co += to;
                prevcoa = to;
                prevcea = te;
            }
            preva=i;
        }
        else
        {
            if((i-prevb+1)%2==0)
            {
                te = prevcob + 1;
                to = prevceb;
                ce += te;
                co += to;
                prevcob = to;
                prevceb = te;
            }
            else
            {
                te = prevceb;
                to = prevcob+1;
                ce += te;
                co += to;
                prevcob = to;
                prevceb = te;
            }
            prevb=i;
        }
    // cout<<ce<<" "<<co<<"\n";
    }
    co += n;
    cout<<ce<<" "<<co<<"\n";
    return 0;
}