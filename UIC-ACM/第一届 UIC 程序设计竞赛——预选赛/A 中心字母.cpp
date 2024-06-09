#include <bits/stdc++.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve()
{
    std::string s;
    std::cin >> s;
    std::cout << s[s.length() / 2];
}
signed main()
{
    for (int T = 1; T--; solve());
    return 0;
}