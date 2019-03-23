#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2, v;
    cin >> s1 >> s2 >> v;
    int m = s1.length();
    int n = s2.length();
    int L[m + 1][n + 1];
    string s;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            else

                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    // backtrack
    int i=m,j=n;
    while(i!=0 && j!=0)
    {
        if(L[i][j] == L[i-1][j])
        {
            i--;
        }
        else if (L[i][j] == L[i][j-1])
            j--;
        else if(L[i][j]==L[i-1][j-1]+1)
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;
    
}