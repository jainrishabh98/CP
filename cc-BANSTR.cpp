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
        ll n, p;
        cin >> n >> p;
        string s;
        cin >> s;
        int pre[n + 1];
        pre[0] = 0;
        stack<int> st;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1];
            if (s[i - 1] == 'b')
                pre[i]++;
            else
                st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                if (st.empty() || st.top() <= i)
                {
                    if (p >= 2)
                    {
                        s[i] = 'a';
                        p -= 2;
                    }
                }
                else
                {
                    int j = st.top();
                    st.pop();
                    // cout<<i+1<<" "<<j<<"\n";
                    int nb = pre[j] - pre[i];
                    int cnt = nb - (pre[j] - pre[j - nb]);
                    if (cnt <= p - 1)
                    {
                        s[i] = 'a';
                        p -= 2;
                        st.push(j);
                    }
                    else if (p > 0)
                    {
                        s[i] = 'a';
                        s[j - 1] = 'b';
                        p--;
                    }
                }
            }
        }
        cout << s << "\n";
    }
}