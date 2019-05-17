#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int flag=0;
    int a,b;
    for(int i=5;i*i<=k;i++)
    {
        if(k%i==0)
        {
            if(i>=5 && k/i>=5)
            {
                flag=1;
                a = i;
                b = k/i;
                break;                
            }
        }
    }
    if(flag==0)
    {
        cout<<-1;
        return 0;
    }
    char s[a][b];
    queue <char> q;
    q.push('a');
    q.push('e');
    q.push('i');
    q.push('o');
    q.push('u');
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            s[i][j] = q.front();
            q.push(q.front());
            q.pop();
        }
        q.push(q.front());
        q.pop();
    }
    for(int i=5;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(j<5)
            {
            s[i][j] = q.front();
            q.push(q.front());
            q.pop();
            }
            else
                s[i][j]='a';
        }
    }
    for(int j=5;j<b;j++)
    {
        for(int i=0;i<5;i++)
        {
            s[i][j] = q.front();
            q.push(q.front());
            q.pop();
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<s[i][j];
        }
    }

}