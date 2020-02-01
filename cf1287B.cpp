#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s[n];
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        mp[s[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string temp = "";
            for (int l = 0; l < k; l++)
            {
                if (s[i][l] == s[j][l])
                {
                    temp.push_back(s[i][l]);
                }
                else
                {
                    if (s[i][l] != 'S' && s[j][l] != 'S')
                    {
                        temp.push_back('S');
                    }
                    else if (s[i][l] != 'E' && s[j][l] != 'E')
                    {
                        temp.push_back('E');
                    }
                    else
                        temp.push_back('T');
                }
            }
            if (mp.find(temp) != mp.end() && temp != s[i] && temp != s[j])
                ans++;
        }
    }
    cout << ans / 3;
}