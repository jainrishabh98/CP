#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int l = s.length();
    int fl = 0;
    int cnt = 0;
    while (s.substr(0, l / 2) == s.substr((l+1) / 2, l / 2) && l >= 2)
    {
        s = s.substr(0, l / 2);
        l = ceil(l / 2.0);
        cnt++;
    }
    if (l > 1)
    {
        if(l%2==0)
        {
            cout<<"1";
        }
        else
        {
            int temp = pow(2,cnt);
            cout<<temp*2 + temp -1;
        }
    }
    else
    {
        cout << "Impossible";
    }
}