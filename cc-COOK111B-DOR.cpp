#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, c, p;
        cin >> l >> r;
        if (r == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        c = l ^ r;
        if(c==0)
        {
            cout<<r<<"\n";
            continue;
        }
        p = 0;
        while (c != 0)
        {
            c /= 2;
            p++;
        }
        c = (long long)pow((long long)2, p - 1);
        c--;
        cout << (r | c) << "\n";
    }
}