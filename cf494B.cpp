#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
ll a[100005], q1[100005], q2[100005], lps[200005];
bool good_ind[100005];
int main()
{
    string s, t;
    cin >> s >> t;
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < t.length())
    {
        if (t[i] == t[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    i = 0; 
    int j = 0; 
    while (i < s.length()) { 
        if (t[j] == s[i]) { 
            j++; 
            i++; 
        } 
        if (j == t.length()) { 
            good_ind[i-1] = true;
            j = lps[j - 1]; 
        } 
        else if (i < s.length() && t[j] != s[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 

    for (int i = 1; i <= s.length(); i++)
    {
        if (good_ind[i-1])
        {   
            (a[i] = q2[i - t.length()] + i - t.length() + 1)%=m;
        }
        else
        {
            a[i] = a[i - 1];
        }
        (q1[i] = a[i] + q1[i - 1])%=m;
        (q2[i] = q1[i] + q2[i - 1])%=m;
    }
    cout<<q1[s.length()];

}