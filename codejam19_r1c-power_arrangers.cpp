#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, f;
    cin >> t >> f;
    while(t--)
    {
        vector<int> v[5];
        char x;
        for (int i = 1; i <= 595; i += 5)
        {
            cout << i << endl;
            cin >> x;
            v[x - 'A'].push_back(i);
        }
        int p[5];
        for (int i = 0; i < 5; i++)
        {
            if (v[i].size() == 23)
            {
                p[0] = i;
                break;
            }
        }
        vector<int> v1[5];
        for (auto i : v[p[0]])
        {
            cout << i + 1 << endl;
            cin >> x;
            v1[x - 'A'].push_back(i + 1);
        }
        for (int i = 0; i < 5; i++)
        {
            if (v1[i].size() == 5)
            {
                p[1] = i;
                break;
            }
        }
        vector<int> v2[5];
        for (auto i : v1[p[1]])
        {
            cout << i + 1 << endl;
            cin >> x;
            v2[x - 'A'].push_back(i + 1);
        }
        for (int i = 0; i < 5; i++)
        {
            if (v2[i].size() == 1)
            {
                p[2] = i;
                break;
            }
        }
        cout << v2[p[2]][0] + 1 << endl;
        cin >> x;
        p[4] = x - 'A';
        cout << v2[p[2]][0] + 2 << endl;
        cin >> x;
        p[3] = x - 'A';
        for (int i = 0; i < 5; i++)
        {
            cout << (char)(p[i] + 'A');
        }
        cout << endl;
        cin >> x;
        if (x == 'N')
            return 0;
    }
}