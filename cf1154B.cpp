#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    if (s.size() >= 4)
    {
        cout << -1;
        return 0;
    }
    else if (s.size() < 3)
    {
        int d = *(--s.end()) - *s.begin();
        if (d % 2 == 0)
            cout << d / 2;
        else
            cout << d;
    }
    else
    {
        int d = *(--s.end()) - *s.begin();
        auto itr = s.begin();
        itr++;
        if (d % 2 == 0 && (*itr - *s.begin()) == d / 2)
        {
            cout << d / 2;
        }
        else
            cout << -1;
    }
}