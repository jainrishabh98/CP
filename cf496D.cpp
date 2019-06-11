#include <bits/stdc++.h>
using namespace std;
struct st{
    int aa,bb;
};
bool comp(st x,st y)
{
    return (x.aa == y.aa) ? (x.bb < y.bb) : (x.aa < y.aa);
}
int cnt[2][100005];
int a[100005];
vector <st> ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]--;
        cnt[a[i]][i]++;
    }
    for(int i=0;i<=1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cnt[i][j] += cnt[i][j-1];
        }
    }
    for(int t=1;t<=n;t++)
    {
        int i=1,fl=0;
        int cn[2]={0,0};
        while(i<=n)
        {
            int low,high,mid,ans=n+1,hero=2;
            low = i;
            high = n;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(cnt[0][mid]-cnt[0][i-1] >=t)
                {
                    ans = mid;
                    high = mid-1;
                    hero = 0;
                }
                else if(cnt[1][mid]-cnt[1][i-1]>=t)
                {
                    ans = mid;
                    high = mid-1;
                    hero = 1;
                }
                else
                {
                    low = mid+1;
                }
            }
            if(ans == n+1)
                fl=1;
            else
                cn[hero]++;
            // cout<<t<<" "<<i<<" "<<hero<<" "<<ans<<"\n";
            i = ans+1;
        }
        if(cn[a[n]]==max(cn[0],cn[1]) && cn[0]!=cn[1] && fl==0)
        {
            st temp;
            temp.aa = cn[a[n]];
            temp.bb = t;
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),comp);
    cout<<ans.size()<<"\n";
    for(auto i:ans)
    {
        cout<<i.aa<<" "<<i.bb<<"\n";
    }
} 