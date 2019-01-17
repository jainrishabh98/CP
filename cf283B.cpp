#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
long long int n , a[N] , vis[N][5] , dp[N][5] , q;

long long int dfs(int x , int t)
{
	if(x < 0 || x > n - 1)
		return 0;
	if(vis[x][t] == 1)
		return -1;
	if(vis[x][t] == 2)
		return dp[x][t];
	vis[x][t] = 1;
	if(t)
		q = dfs(x - a[x] , 0);
	else
		q = dfs(x + a[x] , 1);
	vis[x][t] = 2;
	if(q == -1)
		dp[x][t] = -1;
	else
		dp[x][t] = q + a[x];
	return dp[x][t];
}

int main()
{
	cin >> n;
	for(int i = 1 ; i < n ; i++)
		cin >> a[i];
	vis[0][0] = 1;
	for(int i = 1 ; i < n ; i++)
		if(!vis[i][1])
			dfs(i , 1);
	for(int i = 1 ; i < n ; i++)
	{
		if(dp[i][1] == -1)
			cout << -1 << '\n';
		else
			cout << dp[i][1] + i << '\n';
	}
}