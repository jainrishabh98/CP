#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> a,b;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push(x);
    }
    int flag = 0;
    int cnt = 0;
    while (flag == 0)
    {
        flag = 1;
        for (int i = a.size()-1; i > 0; i--)
        {
            int temp = a.top();
            a.pop();
            if (temp < a.top())
            {
                flag = 0;
            }
            else
            {
                b.push(temp);
            }
        }
        while(!b.empty())
        {
            int temp = b.top();
            b.pop();
            a.push(temp);
        }
        if (flag == 0)
            cnt++;
    }
    cout << cnt;
}