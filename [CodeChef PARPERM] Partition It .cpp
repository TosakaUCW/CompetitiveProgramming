#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int M = 1e5;
bool pri[M + 5];
void init()
{
    for (int i = 2; i <= M; i++) pri[i] = 1;
    for (int i = 2; i * i <= M; i++)
        if (pri[i])
            for (int j = i + i; j <= M; j+= i)
                pri[j] = 0;

}
int n, k;
std::vector<int> a, b;
#define pb emplace_back
void solve()
{
    n = read(), k = read();
    a.clear(), b.clear();
    for (int i = n / 2 + 1; i <= n; i++)
        if (pri[i]) a.pb(i);
        else b.pb(i);
    for (int i = 2; i <= n / 2; i++) b.pb(i);
    a.pb(1);
    if (k <= a.size())
    {
        puts("Yes");
        for (int i = 0; i < k; i++) printf("%d ", a[i]);
        puts("");
    }
    else if (k >= n - a.size())
    {
        puts("Yes");
        for (int x : b) printf("%d ", x);
        for (int i = 0; i < k - n + a.size(); i++) printf("%d ", a[i]);
        puts("");
    }
    else puts("No");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    init();
    for (int T = read(); T--; solve());
    return 0;
}