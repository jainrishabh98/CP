#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    x = a[n - 1];
    a.pop_back();
    if (!a.empty())
    {
        cout << a[0] << " " << x << " ";
        for (int i = 1; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
        cout << x;
}