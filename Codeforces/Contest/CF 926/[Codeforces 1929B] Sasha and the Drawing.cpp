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
    int n = read(), k = read();
    if (4 * n - 4 >= k) cout << (k + 1) / 2 << "\n";
    else cout << k - 2 * n + 2 << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}
