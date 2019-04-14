#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        string s,a;
        int n;
        cin>>n;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='E')
                a.push_back('S');
            else
                a.push_back('E');
        }
        cout << "Case #" << j << ": " << a << "\n";
    }
}