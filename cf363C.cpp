#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string t;
    if(s.length()==1)
        {cout<<s;return 0;}
    t.push_back(s[0]);
    t.push_back(s[1]);
    int l = 2;
    int flag = 0;
    int ans = 0, fl2 = 0;
    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] == t[l - 1] && s[i] == t[l - 2])
        {
            continue;
        }
        else if (s[i] == t[l - 1] && t[l - 2] == t[l - 3] && l >= 3)
        {
            continue;
        }
        else
        {
            t.push_back(s[i]);
            l++;
        }
    }
    cout << t;
}