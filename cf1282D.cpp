#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2,s;
    for (int i = 1; i <= 300; i++)
    {
        s1.push_back('a');
        s2.push_back('b');
    }
    int x, la, lb;
    cout << s1 << endl;
    cin >> x;
    if (x == 0)
        return 0;
    la = 300 - x;
    cout << s2 << endl;
    cin >> x;
    if (x == 0)
        return 0;
    lb = 300 - x;
    int len = la + lb;
    for(int i=1;i<=len;i++)
    {
        s.push_back('a');
    }
    if(lb == 0)
    {
        cout<<s<<endl;
        cin>>x;
        return 0;
    }
    int i = 0;
    int prev = lb;
    while (i != len)
    {
        s[i] = 'b';
        cout << s << endl;
        cin >> x;
        if (x == 0)
            return 0;
        if (x >= prev)
            s[i] = 'a';
        else
            prev = x;
        i++;
    }
}