#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt = 0;
    string ans;
    int last = 0;
    for(int i=0,j=n-1;i<=j;)
    {
        if(i==j)
        {
            ans.push_back('L');
            cnt++;
            i++;
            j--;
            continue;
        }
        if(a[i] < a[j])
        {
            if(a[i] > last)
            {
            ans.push_back('L');
            cnt ++;
            last = a[i];
            i++;
            }
            else
            {
                if(a[j] > last)
                {
                    while(a[j] > last)
                    {
                        ans.push_back('R');
                        cnt++;
                        last = a[j];
                        j--;
                        if(j<=i)
                            break;
                    }
                }
                break;
            }
            
            
        }
        else if(a[j] < a[i])
        {
            if(a[j] > last)
            {
            ans.push_back('R');
            cnt ++;            
            last = a[j];
            j--;
            }
            else
            {
                if(a[i] > last)
                {
                    while(a[i] > last)
                    {
                        ans.push_back('L');
                        cnt++;
                        last = a[i];
                        i++;
                        if(i>=j)
                            break;
                    }
                }
                break;
            }
        }
        else
        {
            int l = i;
            int r = j;
            int cnt1=1,cnt2=1;
            for(int k=l;k<r;k++)
            {
                if(a[k] >= a[k+1])
                    break;
                cnt1++;
            }
            for(int k=r;k>l;k--)
            {
                if(a[k] >= a[k-1])
                    break;
                cnt2++;
            }
            if(cnt1>=cnt2)
            {
                cnt += cnt1;
                while(cnt1--)
                    ans.push_back('L');
            }
            else
            {
                cnt += cnt2;
                while(cnt2--)
                    ans.push_back('R');
            }
            break;
        }
    }
    cout<<cnt<<"\n"<<ans;
}