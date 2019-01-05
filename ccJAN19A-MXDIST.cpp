#include <bits/stdc++.h>
using namespace std;
struct st
{
    int lu, ld, ru, rd,ul,ur,dl,dr;
};
vector<st> segtree;
vector<int> arr;
vector<int> x;
vector<int> y;
int qlow, qhigh, p, diff;
int rsmall(int x, int y, int a, int b)
{
    if (x < y)
        return a;
    else
        return b;
}
int rbig(int x, int y, int a, int b)
{
    if (x < y)
        return b;
    else
        return a;
}
int condn(int lchild, int rchild, int c)
{
    switch (c)
    {
    case 1:
    {
        if (x[segtree[lchild].ld] == x[segtree[rchild].ld])
            return rsmall(y[segtree[lchild].ld], y[segtree[rchild].ld], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].ld], x[segtree[rchild].ld], lchild, rchild);
    }
    case 2:
    {
        if (x[segtree[lchild].lu] == x[segtree[rchild].lu])
            return rbig(y[segtree[lchild].lu], y[segtree[rchild].lu], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].lu], x[segtree[rchild].lu], lchild, rchild);
    }
    case 3:
    {
        if (x[segtree[lchild].rd] == x[segtree[rchild].rd])
            return rsmall(y[segtree[lchild].rd], y[segtree[rchild].rd], lchild, rchild);
        else
            return rbig(x[segtree[lchild].rd], x[segtree[rchild].rd], lchild, rchild);
    }
    case 4:
    {
        if (x[segtree[lchild].ru] == x[segtree[rchild].ru])
            return rbig(y[segtree[lchild].ru], y[segtree[rchild].ru], lchild, rchild);
        else
            return rbig(x[segtree[lchild].ru], x[segtree[rchild].ru], lchild, rchild);
    }
    case 5:
    {
        if (x[segtree[lchild].ur] == x[segtree[rchild].ur])
            return rbig(y[segtree[lchild].ur], y[segtree[rchild].ur], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].ur], x[segtree[rchild].ur], lchild, rchild);
    }
    case 6:
    {
        if (x[segtree[lchild].ul] == x[segtree[rchild].ul])
            return rbig(y[segtree[lchild].ul], y[segtree[rchild].ul], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].ul], x[segtree[rchild].ul], lchild, rchild);
    }
    case 7:
    {
        if (x[segtree[lchild].dl] == x[segtree[rchild].dl])
            return rbig(y[segtree[lchild].dl], y[segtree[rchild].dl], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].dl], x[segtree[rchild].dl], lchild, rchild);
    }
    case 8:
    {
        if (x[segtree[lchild].dr] == x[segtree[rchild].dr])
            return rbig(y[segtree[lchild].dr], y[segtree[rchild].dr], lchild, rchild);
        else
            return rsmall(x[segtree[lchild].dr], x[segtree[rchild].dr], lchild, rchild);
    }
    }
}
void build(int low, int high, int pos)
{
    if (low == high)
    {
        segtree[pos].ld = low;
        segtree[pos].rd = low;
        segtree[pos].lu = low;
        segtree[pos].ru = low;
        segtree[pos].dl = low;
        segtree[pos].dr = low;
        segtree[pos].ur = low;
        segtree[pos].ul = low;
        return;
    }
    int mid = (low + high) / 2;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;
    int index;
    build(low, mid, lchild);
    build(mid + 1, high, rchild);
    // leftmost down
    index = condn(lchild, rchild, 1);
    segtree[pos].ld = segtree[index].ld;
    // leftmost upper
    index = condn(lchild, rchild, 2);
    segtree[pos].lu = segtree[index].lu;
    // rightmost down
    index = condn(lchild, rchild, 3);
    segtree[pos].rd = segtree[index].rd;
    // rightmost upper
    index = condn(lchild, rchild, 4);
    segtree[pos].ru = segtree[index].ru;
    // uppermost right
    index = condn(lchild, rchild, 5);
    segtree[pos].ur = segtree[index].ur;
    // uppermost left
    index = condn(lchild, rchild, 6);
    segtree[pos].ul = segtree[index].ul;
    // downmost left
    index = condn(lchild, rchild, 7);
    segtree[pos].dl = segtree[index].dl;
    // downmost right
    index = condn(lchild, rchild, 8);
    segtree[pos].dr = segtree[index].dr;
}
st query(int low, int high, int pos)
{
    if (qlow <= low && qhigh >= high) // total overlap
        return segtree[pos];
    if (qlow > high || qhigh < low) // no overlap
        return 0;
    int mid = (low + high) / 2;
    st temp;
    query(low, mid, 2 * pos + 1);
    query(mid + 1, high, 2 * pos + 2);
}
int main()
{
    int n;
    cin >> n;
    arr.assign(n, 0);
    x.assign(n, 0);
    y.assign(n, 0);
    int temp = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, temp) - 1;
    // segtree.assign(max_size,0);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    build(0, n - 1, 0);
    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> qlow >> qhigh;
        qlow--;
        qhigh--;
        int ans = query(0, n - 1, 0);
    }
}