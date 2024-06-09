#include <bits/stdc++.h>
// #define int long long
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
int a[N];
void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    std::sort(a + 1, a + 1 + n);
    if (a[n] == a[1]) return puts("NO"), void();
    int c = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1) c++;
    if (c > 1) return puts("NO"), void();
    if (a[2] != a[1]) return puts("YES"), void();
    for (int i = 2; i <= n; i++)
        if (a[i] % a[1] != 0)
            return puts("YES"), void();
    puts("NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}