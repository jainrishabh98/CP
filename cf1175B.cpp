#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, fl = 0;
    cin >> l;
    ll x = 0;
    ll mul = 1, num;
    vector<int> st;
    stack <int> ss;
    string s;
    ll mx = pow(2, 32) - 1;
    for (int i = 1; i <= l; i++)
    {
        cin >> s;
        if (s == "for")
        {
            cin >> num;
            st.push_back(num);
        }
        else if (s == "end")
        {
            if (st.back() > 0)
                st.pop_back();
            else
                st.push_back(-1);
        }
        else
        {
            st.push_back(0);
        }
    }
    int n = st.size();
    for(int i=0;i<n;i++)
    {
        if(st[i] > 0)
        {
            mul *= st[i];
            ss.push(st[i]);
            if(mul > mx)
            {
                fl=1;
                break;
            }
        }
        else if(st[i]==0)
        {
            x += mul;
            if(x > mx)
            {
                fl=1;
                break;
            }
        }
        else
        {
            mul /= ss.top();
            ss.pop();
        }
    }
    if (fl == 1 || x > mx)
    {
        cout << "OVERFLOW!!!";
    }
    else
    {
        cout << x;
    }
}