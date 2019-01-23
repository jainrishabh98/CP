#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    long long int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {

        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == s[i])
            {
                st.pop();
                cnt++;
            }
            else
                st.push(s[i]);
        }
    }

    if (cnt & 1)
        cout << "Yes";
    else
        cout << "No";
}