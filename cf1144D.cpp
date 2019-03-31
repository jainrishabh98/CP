#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(mp.find(a[i])==mp.end())
            mp[a[i]] = 1;
        else
            mp[a[i]] = mp[a[i]] + 1;
    }
    int val,mx=0;
    vector <int> s;
    for(auto i:mp)
    {
        if(i.second > mx)
        {
            val = i.first;
            mx = i.second;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==val)
        {
            s.push_back(i);
        }
    }
    sort(s.begin(),s.end());
    int k = n - mx;
    cout<<k<<"\n";
    for(int i=0;i<s.size()-1;i++)
    {
        int j = s[i]+1;
        int p = s[i];
        while(j!=s[i+1])
        {
            if(a[j] > val)
            {
                cout<<2<<" "<<j+1<<" "<<p+1<<"\n";
            }
            else
            {
                cout<<1<<" "<<j+1<<" "<<p+1<<"\n";
            }
            p++;
            j++;
        }
    }
    if(s[0]!=0)
    {
        int j = s[0]-1;
        int p = s[0];
        while(j!=-1)
        {
            if(a[j] > val)
            {
                cout<<2<<" "<<j+1<<" "<<p+1<<"\n";
            }
            else
            {
                cout<<1<<" "<<j+1<<" "<<p+1<<"\n";
            }
            p--;
            j--;
        }
    }
    if(s[s.size()-1]!=n-1)
    {
        int j = s[s.size()-1]+1;
        int p = s[s.size()-1];
        while(j!=n)
        {
            if(a[j] > val)
            {
                cout<<2<<" "<<j+1<<" "<<p+1<<"\n";
            }
            else
            {
                cout<<1<<" "<<j+1<<" "<<p+1<<"\n";
            }
            p++;
            j++;
        }
    }
}