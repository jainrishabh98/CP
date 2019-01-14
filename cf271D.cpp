#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int c[26];
    char x;
    for (int i = 0; i < 26; i++)
    {
        cin >> x;
        c[i] = '1' - x;
    }
    int k;
    cin >> k;
    // important values for proper hashing
    ll m = 59604644783353249; // prime number close to 10^17 (so that m*a does not overflow also)
    ll a = 26; // number of distinct input characters
    vector<ll> hashed;
    ll h, j;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        h = 0, j = i;
        while (sum + c[s[j] - 'a'] <= k && j < n)
        {
            // cout<<s[j];
            h = ((h * a) % m + (s[j] - 'a' + 1)) % m;
            hashed.push_back(h);
            sum += c[s[j] - 'a'];
            j++;
        }
        // cout<<" ";
    }
    sort(hashed.begin(), hashed.end());
    ll result = 0;
    if (hashed.size() >= 1)
        result++;
    for (int i = 1; i < hashed.size(); i++)
    {
        if (hashed[i] == hashed[i - 1])
            continue;
        result++;
    }
    cout << result << "\n";
    return 0;
}