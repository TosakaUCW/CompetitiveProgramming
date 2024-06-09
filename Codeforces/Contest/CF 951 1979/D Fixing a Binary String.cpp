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
const int N = 1e5 + 5;
// const int INF = 1e18;
int a[N], s[N], tag[N];
void solve()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);

    int cnt = 1;
    s[1] = 1, tag[1] = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1]) s[cnt]++;
        else s[++cnt] = 1, tag[cnt] = a[i];

    int flag = 1, s1 = 0, s2 = 0, pos1 = 0, pos2 = 0;
    for (int i = 1; i <= cnt; i++)
        if (s[i] != k)
        {
            flag = 0;
            if (!pos1) pos1 = i;
            else if (!pos2) pos2 = i;
            else return puts("-1"), void();
        }
    if (flag) return printf("%d\n", n), void();

    int ans = -1;
    if (!pos2)
    {
        if (s[pos1] == 2 * k && tag[pos1] != tag[cnt])
            ans = pos1 * k;
    }
    if (pos1 && pos2)
    {
        if (pos2 == cnt && s[pos2] <= k && ((s[pos1] + s[pos2] == k || s[pos1] + s[pos2] == 2 * k) && tag[pos1] == tag[pos2]))
            ans = k * (pos1 - 1) + (k - s[pos2]);
    }

    printf("%d\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}