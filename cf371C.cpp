#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;
    ll n[3], p[3], r, cnt[3] = {0};
    cin >> n[0] >> n[1] >> n[2] >> p[0] >> p[1] >> p[2] >> r;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
            cnt[0]++;
        else if (s[i] == 'S')
            cnt[1]++;
        else
            cnt[2]++;
    }
    ll low = 0,high = 1e15;
    ll ans,mid;
    while(low<=high)
    {
        mid = (low + high)/2;
        ll pp = max((ll)0,cnt[0]*mid - n[0])*p[0] + max((ll)0,cnt[1]*mid - n[1])*p[1] + max((ll)0,cnt[2]*mid - n[2])*p[2];
        if(pp <= r)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout<<ans;
}