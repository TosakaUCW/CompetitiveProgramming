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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, m, a[N];
std::vector<int> manacher(string s)
{
    string t = "#";
    for (auto ch : s) t += ch, t += '#';
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (2 * j - i >= 0 and j + r[j] > i) r[i] = std::min(r[2 * j - i], j + r[j] - i);
        while (i - r[i] >= 0 and i + r[i] < n and t[i - r[i]] == t[i + r[i]]) r[i]++;
        if (i + r[i] > j + r[j]) j = i;
    }
    return r;
}
void solve()
{
    n = read(), m = read();
    string s; cin >> s;
    vector<int> f1(n), f2(n);
    for (int i = n - 1; ~i; i--)
        f1[i] = i + 1 < n and s[i] == s[i + 1] ? f1[i + 1] : i,
        f2[i] = i + 2 < n and s[i] == s[i + 2] ? f2[i + 2] : i;
    auto rad = manacher(s);
    for (int l, r; m--; )
    {
        l = read() - 1, r = read() - 1;
        int ans = 0, len = r - l + 1;
        if (f1[l] < r)
        {
            // 存在偶数 k
            int m = (len - 1) - (len - 1) % 2;
            ans += (m + 2) * (m / 2) / 2;
        }
        if (f2[l] + 1 < r or f2[l + 1] + 1 < r)
        {
            // 存在奇数 k
            int m = len - 1 - len % 2;
            ans += (m + 3) * ((m - 1) / 2) / 2;
        }
        if (rad[l + r + 1] < len) ans += len;
        cout << ans << '\n';
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}