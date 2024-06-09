#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long
#define lowbit(x) (x & -x)

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;

int n, ans;
int c[N];

struct Node
{
    int val, pos;
    bool friend operator<(Node a, Node b) { return a.val == b.val ? a.pos > b.pos : a.val > b.val; }
} a[N];

void add(int x, int k)
{
    for (; x <= n; x += lowbit(x))
        c[x] += k;
}

int query(int x)
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += c[x];
    return res;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = Node{read(), i};
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        add(a[i].pos, 1), ans += query(a[i].pos - 1);
    printf("%lld", ans);
    return 0;
}