#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<int, int> mp, mp2;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<int> v1, v2;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            v1.push_back(a[i]);
            mp[a[i]] = 1;
        }
        else if (mp2.find(a[i]) == mp2.end())
        {
            v2.push_back(a[i]);
            mp2[a[i]] = 1;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    cout<<v1.size()<<"\n";
    sort(v1.begin(),v1.end());
    for(auto i:v1)
        cout<<i<<" ";
    cout<<"\n"<<v2.size()<<"\n";
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    for(auto i:v2)
        cout<<i<<" ";
    
}