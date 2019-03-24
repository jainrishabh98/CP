#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
string dp[101][101];
ll MAX = (ll)pow(2, 63) - (ll)25;
ll p = 53;
vll uuu;
string v;
ll po[102];

ll vir(string s, string v)
{
    uuu.clear();
    ll hs[s.length() + 1];
    hs[0] = s[0];
    for (ll i = 1; i < s.length(); i++)
    {
        hs[i] = (hs[i - 1] + s[i] * po[i]) % MAX;
    }
    ll hv = 0;
    for (ll i = 0; i < v.length(); i++)
        hv = (hv + v[i] * po[i]) % MAX;
    ll num = 0;
    for (ll i = v.length() - 1; i < s.length(); i++)
    {
        ll temp, c;
        if (i == v.length() - 1)
            temp = hs[i], c = hv;
        else
            temp = hs[i] - hs[i - v.length()], c = (hv * po[i - v.length() + 1]) % MAX;
        if (c == temp)
            num++, uuu.push_back(i - v.length() + 1);
    }
    return num;
}
string comp(string s1, string s2, string s3)
{
    ll n1, n2, n3;
    n1 = s1.length();
    n2 = s2.length();
    n3 = s3.length();
    n1 = n1 - vir(s1, v);
    n2 = n2 - vir(s2, v);
    n3 = n3 - vir(s3, v);
    if (n3 >= n1 && n3 >= n2)
        return s3;
    if (n2 >= n1 && n2 >= n3)
        return s2;
    if (n1 >= n2 && n1 >= n3)
        return s1;
}

int main()
{
    string s1, s2,s="";
    cin >> s1 >> s2 >> v;
    ll n=s1.length(),m=s2.length();
    po[0] = 1;
    for (ll i = 1; i < 101; i++)
        po[i] = (po[i - 1] * p) % MAX;
    
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            dp[i][j] = "";

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            string temp = "";
            if (s1[i] == s2[j])
                temp = dp[i][j] + s1[i];
            dp[i + 1][j + 1] = comp(dp[i + 1][j], dp[i][j + 1], temp);
        }
    }
    s = dp[n][m];
    if (s.length() == 0)
    {
        cout << "0";
        return 0;
    }
    string s5 = s;
    while (vir(s, v))
    {
        if (uuu.size() > 0)
        {
            s.replace(uuu[0] + v.length() - 1, 1, "");
        }
    }

    while (vir(s5, v))
    {
        
        if (uuu.size() > 0)
        {
            s5.replace(uuu[0], 1, "");
        }
    }
    if ((s.length() == 0) && (s5.length() == 0))
    {
        cout << "0";
        return 0;
    }
    if (s.length() > s5.length())
        cout << s;
    else
        cout << s5;
}