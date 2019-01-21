#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;

int tin[N], tout[N];
int isprime[N];
int bit[N];
int a[N];
vector<int> g[N];
int n, q, timer;

void update(int i, int x){
    while(i <= N-5){
        bit[i] += x;
        i = i + (i & (-i));
    }
}

int sum(int i){
    int ans = 0;
    while(i != 0 && i > 0){
        ans += bit[i];
        i = (i & (i-1));
    }
    return ans;
}

void dfs(int v, int p){
    tin[v] = ++timer;
    for(auto it : g[v]){
        if(it == p)
            continue;
        dfs(it, v);
    }
    tout[v] = timer;
}

void sieve(){
    isprime[0] = isprime[1] = 1;
    for(int i = 2; i < N; ++i){
        if(!isprime[i]){
            for(int j = 2; i * j < N; ++j){
                isprime[i * j] = 1;
            }
        }
    }
}
bool check(int val){
    if(val < 0)
        return false;
    return !isprime[val];
}
void clear(){
    timer = 0;
    for(int i = 0; i<= n; ++i){
        g[i].clear();
    }
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    memset(bit, 0, sizeof(bit));
}
int main(){
    sieve();
    int t;
    scanf("%d", &t);
    while(t--){
        clear();
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; ++i){
            scanf("%d", a + i);
            if(check(a[i]))
                a[i] = 1;
            else
                a[i] = 0;
        }
        int u, v, type, x;
        for(int i = 1; i < n; ++i){
            scanf("%d %d",&u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(int i = 1; i<= n; ++i){
            if(a[i])
                update(tin[i], a[i]);
        }
        while(q--){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d %d", &u, &x);
                if(check(x)){
                    if(a[u] == 0){
                        update(tin[u], 1);
                        a[u] = 1;
                    }
                }
                else{
                    if(a[u] == 1){
                        update(tin[u], -1);
                        a[u] = 0;
                    }
                }
            }
            else{
                scanf("%d", &u);
                printf("%d\n", sum(tout[u]) - sum(tin[u] - 1));
            }
        }
    }
}