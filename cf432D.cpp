#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int lps[l];
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < l; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    for (int i = 0; i < l; i++)
    {
        cnt[lps[i]]++;
    }
    for(int i=l-1;i>=1;i--)
    {
        cnt[lps[i-1]] += cnt[i];
    }
    int g = lps[l - 1];
    vector <pair<int,int> > p;
    while (g != 0)
    {   
        if(cnt[g]!=0)
            p.push_back(make_pair(g,cnt[g]+1));
        g = lps[g - 1];
    }
    int num = p.size();
    cout << num + 1 << "\n";
    sort(p.begin(),p.end());
    for(int k=0;k<num;k++)
    {
        cout<<p[k].first<<" "<<p[k].second<<"\n";
    }
    cout << l << " " << 1;
}