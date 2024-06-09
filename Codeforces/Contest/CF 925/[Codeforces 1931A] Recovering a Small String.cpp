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
int n, a[N];
void solve()
{
    int x = read();
    string ans = "";
    if (x > 52) ans += char('a' + x - 52 - 1), x -= (ans[0] - 'a' + 1);
    else ans += 'a', x--;
    if (x > 26) ans += char('a' + x - 26 - 1), x -= (ans[1] - 'a' + 1);
    else ans += 'a', x--;
    ans += char('a' + x - 1);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}