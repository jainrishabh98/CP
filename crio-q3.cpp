#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct tr{
    string nm;
    ll num,atm,dtm,pf,in;
};
bool comp(tr x, tr y)
{
    return (x.atm == y.atm) ? (x.dtm < y.dtm) : (x.atm < y.atm);
}
bool comp2(tr x, tr y)
{
    return (x.in < y.in);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        tr s[n];
        string s1,s2,s3;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].nm >> s[i].num >> s1 >> s2 >> s3;
            s[i].in = i;
            s[i].atm = ((s1[0] - '0') * 10 + (s1[1] - '0')) * 3600 + ((s1[3] - '0') * 10 + (s1[4] - '0')) * 60 + (s1[6] - '0') * 10 + (s1[7] - '0');
            s[i].dtm = ((s2[0] - '0') * 10 + (s2[1] - '0')) * 3600 + ((s2[3] - '0') * 10 + (s2[4] - '0')) * 60 + (s2[6] - '0') * 10 + (s2[7] - '0');
            s[i].dtm += ((s3[0] - '0') * 10 + (s3[1] - '0')) * 3600 + ((s3[3] - '0') * 10 + (s3[4] - '0')) * 60 + (s3[6] - '0') * 10 + (s3[7] - '0');
        }
        sort(s,s+n,comp);
        ll et = 0,pf = 1;
        for(int i=0;i<n;i++)
        {
            if(s[i].atm > et)
            {
                s[i].pf = pf;
                et = s[i].dtm;
            }
            else
            {
                
            }
        }
        sort(s,s+n,comp2);
        cout<<pf<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<s[i].nm<<" "<<s[i].num<<" "<<s[i].pf<<"\n";
        }
    }

}