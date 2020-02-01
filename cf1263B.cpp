#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string p[n];
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            mp[p[i]]++;
        }
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[p[i]] > 1)
            {
                k++;
                mp[p[i]]--;
                string s = p[i];
                for (int j = 0; j <= 9; j++)
                {
                    reverse(s.begin(), s.end());
                    s.pop_back();
                    s.push_back(j + '0');
                    reverse(s.begin(), s.end());
                    if (mp.find(s) == mp.end()) 
                    {
                        mp[s] = 1;
                        p[i] = s;
                        break;
                    }
                }
            }
        }
        cout<<k<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<p[i]<<"\n";
        }
        
    }
}