#include <bits/stdc++.h>
using namespace std;
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<"";return out;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
map<int, bool> mp;
vector<int> v;
int n, summ = 0;
bool canplace(int indx, int prev)
{
    if (indx == n)
        return mp[summ];
    for (int i = prev; i <= 9; i++)
    {
        v[indx] = i;
        summ += i * i;
        if (canplace(indx + 1, i))
            return 1;
        summ -= i * i;
    }
    return 0;
}
int main()
{
    for (int i = 1; i <= 9000; i++)
    {
        mp[i * i] = 1;
    }
    int t;
    cin >> t;
    while (t--)
    {
        summ = 0;
        cin >> n;
        v.resize(n);
        if (canplace(0, 1))
            cout << v << "\n";
        else
            cout << "-1\n";
    }
}