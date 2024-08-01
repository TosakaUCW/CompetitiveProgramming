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
const int N = 2e5;
void solve()
{
    int n = read();
    vector<int> a(n);
    for (auto &x : a) x = read();
    if (a[0] == a[n - 1]) puts("NO");
    else 
    {
        puts("YES");
        for (int i = 0; i < n; i++) putchar(i == 1 ? 'B' : 'R');
        puts("");
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}