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
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << 1;
        }
        else
        {
            cout << 7;
        }
        for (int i = 1; i < n / 2; i++)
        {
            cout << 1;
        }
        cout << "\n";
    }
}