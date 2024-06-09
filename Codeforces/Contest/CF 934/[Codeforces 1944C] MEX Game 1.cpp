#include <bits/stdc++.h>
// #define int long long
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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, m, a[N];
void solve()
{
    n = read();
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]] ++;
    for (int i = 0, tmp = 0; i <= n; i++)
    {
        tmp += (cnt[i] == 1);
        if (!cnt[i] or cnt[i] and tmp == 2)
        {
            cout << i << '\n';
            break;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}