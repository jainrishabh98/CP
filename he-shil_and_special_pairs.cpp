// There is nothing in caterpillar that tells you its going to be a butterfly ------------------------------- !
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e8
#define pi pair<ll,ll>
#define pii pair<pi,ll>
#define f first
#define mp make_pair
#define pb push_back
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
ll bt[100011];
int N;
void update(int ind){
	while(ind<=N){
		bt[ind]++;
		ind+=(ind&-ind);
	}
}
ll query(int ind){
	ll ans=0;
	while(ind>0){
		ans+=bt[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
bool func(pii a,pii b){
	return a.f.s<b.f.s;
}
int pos[100011];
ll ans[100011];
int main(){
	freopen("output-10.txt","w",stdout);
	freopen("input-10.txt","r",stdin);
	int M,D;
	cin >> N >> M >> D;
	int p[N+1];
	for(int i=1;i<=N;i++){
		cin >> p[i];
		pos[p[i]]=i;
	}
	vector<pii>Q;
	int l,r,ind;
	rep(i,M){
		cin >> l >> r;
		Q.push_back( mp( mp(l,r),i ) );
	}
	sort(Q.begin(),Q.end(),func);
	int j=0;
	for(int i=1;i<=N;i++){
		for(int k=max(1,p[i]-D);k<=min(N,p[i]+D);k++){
			if(pos[k]<=i){
				update(pos[k]);
			}
		}
		while(j<Q.size() and Q[j].f.s==i){
			ans[Q[j].s]=query(Q[j].f.s)-query(Q[j].f.f-1);
			j++;
		}
	}
	rep(i,M){
		cout<<ans[i]<<"\n";
	}
}