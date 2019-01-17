#include<bits/stdc++.h>
using namespace std;
int x,y,xf,yf;
void my_bfs(int u,int v)
{
    queue <pair<int,pair<int,int> > > q;
    q.push(make_pair(0,make_pair(u,v)));
    int ans=0;
    while(!q.empty())
    {   int cnt = q.front().first;
        int xt = q.front().second.first;
        int yt = q.front().second.second;
        q.pop();
       
        if(xt==xf && yt==yf) {ans = cnt;break;}
        cnt++;
        if(xt+2<=8 && yt-1<=8 && xt+2>=1 && yt-1>=1)
            q.push(make_pair(cnt,make_pair(xt+2,yt-1)));
        if(xt+2<=8 && yt+1<=8 && xt+2>=1 && yt+1>=1)
            q.push(make_pair(cnt,make_pair(xt+2,yt+1)));
        if(xt-2<=8 && yt-1<=8 && xt-2>=1 && yt-1>=1)
            q.push(make_pair(cnt,make_pair(xt-2,yt-1)));
        if(xt-2<=8 && yt+1<=8 && xt-2>=1 && yt+1>=1)
            q.push(make_pair(cnt,make_pair(xt-2,yt+1)));
        if(xt-1<=8 && yt+2<=8 && xt-1>=1 && yt+2>=1)
            q.push(make_pair(cnt,make_pair(xt-1,yt+2)));
        if(xt+1<=8 && yt+2<=8 && xt+1>=1 && yt+2>=1)
            q.push(make_pair(cnt,make_pair(xt+1,yt+2)));
        if(xt+1<=8 && yt-2<=8 && xt+1>=1 && yt-2>=1)
            q.push(make_pair(cnt,make_pair(xt+1,yt-2)));
        if(xt-1<=8 && yt-2<=8 && xt-1>=1 && yt-2>=1)
            q.push(make_pair(cnt,make_pair(xt-1,yt-2)));

    }
    cout<<ans<<"\n";
}
int main ()
{
        int t;
        cin>>t;
        while(t--)
        {
        string c1,c2;
        cin>>c1>>c2;
        x = c1[0] - 'a' + 1;
        y = c1[1] -'1' + 1;
        xf = c2[0] - 'a' + 1;   
        yf = c2[1] - '1' + 1;
        // cout<<x<<" "<<y<<" "<<xf<<" "<<yf<<"\n";
        my_bfs(x,y);
        }
    return 0;
}