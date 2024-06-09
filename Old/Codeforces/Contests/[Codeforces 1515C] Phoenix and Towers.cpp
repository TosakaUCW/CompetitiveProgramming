#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <set>
#include <memory.h>

#define int long long

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m, x;
int b[N];
struct Node
{
    int idx, val;
    bool friend operator<(Node a, Node b) { return a.val == b.val ? a.idx < b.idx : a.val < b.val; }
} a[N];
std::set<Node> S;

void solve()
{
    S.clear(), memset(b, 0, sizeof b);
    n = read(), m = read(), x = read();
    for (int i = 1; i <= n; i++)
        a[i] = {i, read()};
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++)
        S.insert(Node{i, 0});
    for (int i = n; i >= 1; i--)
    {
        Node p = *S.begin();
        S.erase(p);
        p.val += a[i].val, b[a[i].idx] = p.idx;
        S.insert(p);
    }
    Node p = *S.begin(), q = *S.rbegin();
    if (q.val - p.val <= x)
    {
        puts("YES");
        for (int i = 1; i <= n; i++)
            printf("%lld ", b[i]);
        puts("");
    }
    else
        puts("NO");
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
