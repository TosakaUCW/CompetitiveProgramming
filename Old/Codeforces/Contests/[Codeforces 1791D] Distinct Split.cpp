#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n, a[N], b[N];
std::string s;
std::unordered_map<char, bool> map;
void solve()
{
    std::cin >> n >> s;
    s = "*" + s;
    map.clear();
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (!map[s[i]]), map[s[i]] = 1;
    map.clear();
    for (int i = n; i; i--) b[i] = b[i + 1] + (!map[s[i]]), map[s[i]] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = std::max(ans, a[i] + b[i + 1]);
    printf("%d\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}