#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
// const int INF = 1e18;
int n, P, c[N];
void solve()
{
    n = read(), P = read();
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = read(), r = read(), v = read();
        tmp += v;
        if (l == r)
        {
            c[l % P] += v, c[r % P + 1] -= v;
            continue;
        }
        if (r - l + 1 >= P)
        {
            c[0] += v;
            continue;
        }
        int L = l % P, R = r % P;
        if (R < L) c[0] += v, c[R + 1] -= v, c[L] += v;
        else c[L] += v, c[R + 1] -= v;
    }
    int ans = 0, sum = 0;
    for (int i = 0; i < P; i++)
    {
        sum += c[i], ans = std::max(ans, sum);
        // cout << i << ' ' << sum << '\n';
    }
    cout << tmp - ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}