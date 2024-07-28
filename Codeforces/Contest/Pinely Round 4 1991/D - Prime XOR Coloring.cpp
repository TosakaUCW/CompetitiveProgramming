#include <bits/stdc++.h>
using i64 = long long;
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

void solve()
{
    int n = read();
    if (n <= 5)
    {
        if (n == 1) cout << "1\n1\n";
        if (n == 2) cout << "2\n1 2\n";
        if (n == 3) cout << "2\n1 2 2\n";
        if (n == 4) cout << "3\n1 2 2 3\n";
        if (n == 5) cout << "3\n1 2 2 3 3\n";
    }
    else
    {
        cout << "4\n";
        for (int i = 1; i <= n; i++) cout << (4 - i % 4) << ' ';
        puts("");
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}