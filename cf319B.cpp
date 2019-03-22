#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t[n+1],val[n+1];
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        
    }
    stack <int> S;
    int sol = 0;
    for (int i=0; i<n; ++i) {
        t[i] = 0;
        while (S.size()>0 && val[S.top()]<val[i]) {
            t[i] = max(t[i], t[S.top()]+1);
            S.pop();
        }
        if (S.size() == 0) {
            t[i] = -1;
        }
        S.push(i);
        sol = max(sol, t[i]+1);
    }
    cout<<sol;
}