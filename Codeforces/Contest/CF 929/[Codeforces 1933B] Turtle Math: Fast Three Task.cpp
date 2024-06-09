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
int n, a[N];
void solve()
{
    n = read();
    int sum = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum % 3 == 0) return puts("0"), void();
    if ((sum + 1) % 3 == 0) return puts("1"), void();
    for (int i = 1; i <= n; i++)
        if ((sum - a[i]) % 3 == 0)
            return puts("1"), void();
    return puts("2"), void();
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}