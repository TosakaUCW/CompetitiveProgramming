#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
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
int n, a[N], b[N];
void solve()
{
    string s; cin >> n >> s;
    std::vector<int> ans(n, -1), l, r;

    for (int i = 0; i < n; i++)
        if (s[i] == '>') r.pb(i);
        else l.pb(i);
    std::reverse(l.begin(), l.end());
    for (int i = 0, tot = 0; i < n and !l.empty(); i++)
        tot += (l.back() - i) * 2, l.pop_back(), ans[i] = i + 1 + tot;
    for (int i = n - 1, tot = 0; ~i and !r.empty(); i--)
        tot += (i - r.back()) * 2, r.pop_back(), ans[i] = n - i + tot;
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}