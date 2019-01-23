#include <bits/stdc++.h>
using namespace std;
int h[1000001];
int range[1000001];
stack<int> s;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {   
        memset(h,0,sizeof(h));
        memset(range,0,sizeof(range));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> h[i];

        for (int i = n - 1; i >= 0; i--)
        {
            if (!s.empty())
            {
                while (h[i] > h[s.top()])
                {
                    range[s.top()] = s.top() - i;
                    s.pop();
                    if (s.empty())
                        break;
                }
            }
            s.push(i);
        }
        
        while (!s.empty())
        {
            range[s.top()] = s.top()+1;
            s.pop();
        }
        for (int i = 0; i < n; i++)
        {
            cout << range[i] << " ";
        }
        cout<<"\n";
    }
}