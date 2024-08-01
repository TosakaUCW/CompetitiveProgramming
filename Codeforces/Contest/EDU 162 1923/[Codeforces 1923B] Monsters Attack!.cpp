#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
struct Node
{
    int a, x;
    bool friend operator < (Node a, Node b) { return a.x == b.x ? a.a < b.a : a.x < b.x; }
} a[N];
void solve()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i].a = read();
    for (int i = 1; i <= n; i++) a[i].x = abs(read());
    std::sort(a + 1, a + 1 + n);
    int flag = 1;
    for (int i = 1, j = 1, tot = 0; i <= n; i++)
    {
        tot += k;
        for (; j <= n and a[j].x == i; j++) tot -= a[j].a;
        if (tot < 0) { flag = 0; break; }
    }
    puts(flag ? "YES" : "NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}