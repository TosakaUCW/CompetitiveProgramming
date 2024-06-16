#include <bits/stdc++.h>
using i64 = long long;
#define int i64
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, i64 f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    i64 n = read(), k = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1, j = n; i <= j; i++)
    {
        if (k == 0) break;
        if (k >= (a[j] - a[i]) * 2)
            std::swap(a[i], a[j]), k -= (j - i) * 2, j--;
    }
    if (k != 0) return puts("No"), void();
    puts("Yes");
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}