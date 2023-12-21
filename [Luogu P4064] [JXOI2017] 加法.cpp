#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
int n, m, k, p;
int a[N];
struct Node
{
    int l, r;
    bool friend operator<(Node a, Node b) { return a.r < b.r; }
} b[N];

int t[N];
#define lowbit(x) (x & -x)
void add(int x, int p)
{
    for (int i = x; i <= n; i += lowbit(i))
        t[i] += p;
}
int query(int x, int res = 0)
{
    for (int i = x; i >= 1; i -= lowbit(i))
        res += t[i];
    return res;
}

std::priority_queue<Node> Q;

bool judge(int X)
{
    while (!Q.empty()) Q.pop();
    for (int i = 0; i <= n; i++)
        t[i] = 0;
    for (int i = 1; i <= n; i++)
        add(i, a[i]), add(i + 1, -a[i]);
    int now = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        while (b[now].l == i and now <= m)
            Q.push(b[now++]);
        while (query(i) < X and !Q.empty())
        {
            add(Q.top().l, p), add(Q.top().r + 1, -p);
            cnt++, Q.pop();
        }
        if (query(i) < X) return 0;
    }
    return cnt <= k;
}

void solve()
{
    n = read(), m = read(), k = read(), p = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
        b[i].l = read(), b[i].r = read();
    std::sort(b + 1, b + 1 + m, [](Node a, Node b)
              { return a.l == b.l ? a.r > b.r : a.l < b.l; });
    int ans = 0;
    for (int L = 0, R = 2e7 + 1e8; L <= R;)
    {
        int mid = (L + R) >> 1;
        if (judge(mid))
            ans = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    
    /*
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", b[i].l, b[i].r);
    for (int i = 1; i <= 2; i++)
        Q.push(b[i]);
    printf("%d %d\n", Q.top().l, Q.top().r);
    */
    printf("%d\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}