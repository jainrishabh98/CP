#include <bits/stdc++.h>
using namespace std;
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
        string s;
        cin >> s;
        int ans = n;
        for (char i = 'a'; i <= 'z'; i++)
        {
            int prev = -1;
            for (int j = 0; j < n; j++)
            {
                if(s[j]==i)
                {
                    if(prev == -1)
                    {
                        prev = j;
                    }
                    else
                    {
                        ans = min(ans,j-prev);
                        prev = j;
                    }
                }
            }
        }
        cout<<n-ans<<"\n";
    }
}