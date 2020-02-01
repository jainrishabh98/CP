#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string s1 = "twone";
        string s2 = "one";
        string s3 = "two";
        map<int, int> mp;
        int n = s.length();
        for (int i = 0; i <= n-5; i++)
        {
            string temp = s.substr(i, 5);
            if (temp == s1)
            {
                mp[i + 2] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(mp.find(i)!=mp.end()) continue;
            string temp = "";
            int j = i;
            int el = -1;
            while (temp.length() < 3 && j < n)
            {
                if(mp.find(j)==mp.end())
                {
                    temp.push_back(s[j]);
                    if(temp.length()==2)
                        el = j;
                }
                j++;
            }
            if(temp.length() < 3)
                break;
            if(temp == s2)
            {
                mp[el] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(mp.find(i)!=mp.end()) continue;
            string temp = "";
            int j = i;
            int el = -1;
            while (temp.length() < 3 && j < n)
            {
                if(mp.find(j)==mp.end())
                {
                    temp.push_back(s[j]);
                    if(temp.length()==2)
                        el = j;
                }
                j++;
            }
            if(temp.length() < 3)
                break;
            if(temp == s3)
            {
                mp[el] = 1;
            }
        }
        cout<<mp.size()<<"\n";
        for(auto i:mp)
        {
            cout<<i.first+1<<" ";
        }
        cout<<"\n";
    }
}