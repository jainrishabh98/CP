#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, d, fl = 0, aa, bb, cc, dd;
    cin >> a >> b >> c >> d;
    aa = a;
    bb = b;
    cc = c;
    dd = d;
    vector<int> v;
    while (a != 0 && b != 0)
    {
        v.push_back(0);
        a--;
        v.push_back(1);
        b--;
    }
    if (c == 0 && d == 0 && b == 0 && a == 1)
    {
        v.push_back(0);
        a--;
    }
    if (a == 0)
    {
        while (b != 0 && c != 0)
        {
            v.push_back(2);
            c--;
            v.push_back(1);
            b--;
        }
        if (b == 0)
        {
            while (c != 0 && d != 0)
            {
                v.push_back(2);
                c--;
                v.push_back(3);
                d--;
            }
            if (c > 0)
            {
                v.push_back(2);
                c--;
            }
            if (c == 0 && d == 0)
            {
                cout << "YES\n";
                for (auto i : v)
                {
                    cout << i << " ";
                }
                return 0;
            }
        }
    }
    a = aa;
    b = bb;
    c = cc;
    d = dd;
    v.clear();
    while (a != 0 && b != 0)
    {
        v.push_back(1);
        a--;
        v.push_back(0);
        b--;
    }
    if (a == 0 && b > 0)
    {
        v.push_back(1);
        b--;
        while (b != 0 && c != 0)
        {
            v.push_back(2);
            c--;
            v.push_back(1);
            b--;
        }
        if (b == 0)
        {
            while (c != 0 && d != 0)
            {
                v.push_back(2);
                c--;
                v.push_back(3);
                d--;
            }
            if (c > 0)
            {
                v.push_back(2);
                c--;
            }
            if (c == 0 && d == 0)
            {
                cout << "YES\n";
                for (auto i : v)
                {
                    cout << i << " ";
                }
                return 0;
            }
        }
    }
    a = aa;
    b = bb;
    c = cc;
    d = dd;
    v.clear();
    if(a==0 && b==0)
    {
        if(c>=d)
        {
            while(d!=0)
            {
                v.push_back(2);
                v.push_back(3);
                d--;
                c--;
            }
            if(c==1 || c==0)
            {
                cout<<"YES\n";
                for(auto i:v)
                {
                    cout<<i<<" ";
                }
                if(c==1)
                {
                    cout<<2;
                }
                return 0;
            }
        }
        else
        {
           while(c!=0)
            {
                v.push_back(3);
                v.push_back(2);
                c--;
                d--;
            } 
            if(d==1 || d==0)
            {
                cout<<"YES\n";
                for(auto i:v)
                {
                    cout<<i<<" ";
                }
                if(d==1)
                {
                    cout<<3;
                }
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}