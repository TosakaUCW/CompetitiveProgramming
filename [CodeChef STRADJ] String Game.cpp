#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int n;
std::string s;
void solve()
{
    std::cin >> n >> s;
    int a = 0, b = 0;
    for (auto c : s)
        if (c == 48) a++;
        else b++;
    a = std::min(a, b);
    if (a <= 1) puts(a ? "Alice" : "Bob");
    else puts(n % 2 ? "Alice" : "Bob");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}