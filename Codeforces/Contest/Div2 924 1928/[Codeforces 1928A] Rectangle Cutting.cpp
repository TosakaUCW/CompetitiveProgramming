#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1LL << 60;
int n, a[N];
void solve()
{
    int a = read(), b = read();
    if (a < b) std::swap(a, b);
    if (a % 2 == 0)
    {
        // a / 2, b * 2
        int c =  a / 2, d = b * 2;
        if (c < d) std::swap(c, d);
        if (a != c or b != d)
            return puts("YES"), void();
    }
    if (b % 2 == 0)
    {
        int c = b / 2, d = a * 2;
        if (c < d) std::swap(c, d);
        if (a != c or b != d)
            return puts("YES"), void();
    }
    puts("NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}