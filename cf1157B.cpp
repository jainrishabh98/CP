#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    int arr[10];
    for(int i=1;i<=9;i++)
    {
        cin>>arr[i];
    }
    int flag=0;
    string ans;
    for(int i=0;i<a.length();i++)
    {
        int x = a[i] - '0';
        if(arr[x] > x && flag==0)
        {
            flag=1;
            while(arr[x] >= x)
            {
                ans.push_back((char)(arr[x]+'0'));
                i++;
                if(i==a.length())
                    break;
                x = a[i] - '0';
            }
            i--;
        }
        else
        {
            ans.push_back(a[i]);
        }
    }
    cout<<ans;
}