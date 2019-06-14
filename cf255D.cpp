#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, x, y, c;
    cin >> n >> x >> y >> c;
    ll low = 0;
    ll high = c;
    ll mid;
    ll ans=-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll temp = 4*mid + 2*mid*(mid-1) + 1;
        ll y1=0,y2=0,y3=0,y4=0;
        ll aa = min(x - 1, mid), bb = min(n - y, mid), cc = min(n - x, mid), dd = min(y - 1, mid);
        if(aa < mid - bb -1)
        {
            y1 = (mid*(mid-1))/2 - aa*bb;
        }
        else
        {
            y1 = ((mid-aa)*(mid-aa-1))/2 + ((mid-bb)*(mid-bb-1))/2;
        }
        if(bb < mid - cc -1)
        {
            y2 = (mid*(mid-1))/2 - cc*bb;
        }
        else
        {
            y2 = ((mid-cc)*(mid-cc-1))/2 + ((mid-bb)*(mid-bb-1))/2;
        }
        if(cc < mid - dd -1)
        {
            y3 = (mid*(mid-1))/2 - cc*dd;
        }
        else
        {
            y3 = ((mid-cc)*(mid-cc-1))/2 + ((mid-dd)*(mid-dd-1))/2;
        }
        if(dd < mid - aa -1)
        {
            y4 = (mid*(mid-1))/2 - aa*dd;
        }
        else
        {
            y4 = ((mid-aa)*(mid-aa-1))/2 + ((mid-dd)*(mid-dd-1))/2;
        }
        temp -= (mid-aa+mid -bb+mid -cc+mid -dd+y1+y2+y3+y4);
        if (temp >= c)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}