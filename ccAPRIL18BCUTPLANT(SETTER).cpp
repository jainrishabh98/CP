#include <stdio.h>
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int inf = (int)1e9 + 1;

int cnt_v = 1;
vector<int> tree_min;
vector<int> tree_max;

void build(int n, int *initial, int *final)
{
    while (cnt_v < n)
        cnt_v <<= 1;
    tree_min.resize(cnt_v * 2 - 1);
    tree_min.assign(cnt_v * 2 - 1, inf);
    tree_max.resize(cnt_v * 2 - 1);
    tree_max.assign(cnt_v * 2 - 1, -inf);
    for (int i = 0; i < n; i++)
    {
        tree_min[cnt_v - 1 + i] = initial[i];
        tree_max[cnt_v - 1 + i] = final[i];
    }
    for (int i = cnt_v - 2; i >= 0; i--)
    {
        tree_min[i] = min(tree_min[i * 2 + 1], tree_min[i * 2 + 2]);
        tree_max[i] = max(tree_max[i * 2 + 1], tree_max[i * 2 + 2]);
    }
}

int get_min(int x, int lx, int rx, int l, int r)
{
    if (lx >= r || l >= rx)
        return inf;
    else if (lx >= l && rx <= r)
        return tree_min[x];
    else
        return min(get_min(x * 2 + 1, lx, (lx + rx) / 2, l, r), get_min(x * 2 + 2, (lx + rx) / 2, rx, l, r));
}

int get_max(int x, int lx, int rx, int l, int r)
{
    if (lx >= r || l >= rx)
        return -inf;
    else if (lx >= l && rx <= r)
        return tree_max[x];
    else
        return max(get_max(x * 2 + 1, lx, (lx + rx) / 2, l, r), get_max(x * 2 + 2, (lx + rx) / 2, rx, l, r));
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.precision(20);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //Reading input
        int n;
        scanf("%d", &n);
        int initial[n], final[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &initial[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &final[i]);

        //Check possibility
        bool possible = true;
        for (int i = 0; i < n; i++)
            if (initial[i] < final[i])
            {
                possible = false;
                break;
            }
        if (!possible)
        {
            cout << -1 << endl;
            continue;
        }

        //Build Segment Trees
        build(n, initial, final);

        //Sort all final heights in non-increasing order
        vector<pair<int, int> > h(n);
        for (int i = 0; i < n; i++)
            h[i] = {final[i], i};
        sort(h.begin(), h.end(), [](pair<int, int> p1, pair<int, int> p2){ return p1.fi != p2.fi ? p1.fi > p2.fi : p1.se < p2.se;});

        //Count the minimal number of cuts
        int number_of_cuts = 0, last_cut = -1;
        for (int i = 0; i < n; i++)
        {
            if (initial[h[i].se] == final[h[i].se]) //the plant doesn't need cutting
                continue;
            //if (this is the first plant with such height) or (there is a plant in the interval with height < h[i].fi) or (there is a plant in the interval that should have its height in the end > h[i].fi) 
            if ((last_cut == -1 || h[last_cut].fi != h[i].fi) || (get_min(0, 0, cnt_v, h[last_cut].se, h[i].se + 1) < h[i].fi) || (get_max(0, 0, cnt_v, h[last_cut].se, h[i].se + 1) > h[i].fi))
                number_of_cuts++; //start a new cut
            last_cut = i;
        }

        //Print the answer
        cout << number_of_cuts << "\n";
    }
    return 0;
}