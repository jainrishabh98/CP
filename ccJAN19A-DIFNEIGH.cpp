#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m;
        int start = 1;
        int st = 2;int prnt = 0;
        if (n >= 3 && m >= 3)
        {
            k = 4;
            cout<<k<<"\n";
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    start = start ^ 2;
                    prnt = start;
                }
                else
                {
                    st = st ^ 6;
                    prnt = st;
                }
                for (int j = 0; j < m; j++)
                {   
                    cout<<prnt<<" ";
                    if(j%2!=0)
                        prnt  = (i%2==0) ? prnt^2 : prnt^6;
                }
                cout<<"\n";
            }
        }
        else if (n == 1 || m == 1)
        {   prnt = 1;
            k = 2;
            if(n*m <=2) k=1;
            cout<<k<<"\n";
            char c = ' ';
            if(m==1) { c= '\n'; m=n;}
            for (int j = 0; j < m; j++)
                {   
                    cout<<prnt<<c;
                    if(j%2!=0)
                        prnt  = prnt^3;
                }
            if(c==' ') cout<<"\n";
        }
        else if (n==2 && m==2)
        {
            cout<<"2\n";
            cout<<"1 1\n";
            cout<<"2 2\n";
        }
        else
        {
            prnt = 1;
            k = 3;
            cout<<k<<"\n";
            int temp = m;
            if(m==2) temp=n;
            int a[2][temp];
            for (int j = 0; j < temp; j++)
                {   
                    a[0][j] = prnt;
                    if(j%2!=0)  prnt++;
                    if(prnt == 4) prnt = 1;
                }
            a[1][0] = 2;
            prnt = 3;
            for (int j = 0; j < temp-1; j++)
                {   
                    a[1][j+1] = prnt;
                    if(j%2!=0)  prnt++;
                    if(prnt == 4) prnt = 1;
                }
            if(n==2)
            {
                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<m;j++)
                        cout<<a[i][j]<<" ";
                    cout<<"\n";
                }
            }
            else
            {
                for(int j=0;j<n;j++)
                {
                    for(int i=0;i<2;i++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                    cout<<"\n";
                }
            }

        }
    }
    return 0;
}