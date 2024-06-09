#include <bits/stdc++.h>
// #define int long long
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
void solve()
{
    int n = read();
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        printf("? %d %d %d %d\n", p, p, i, i), fflush(stdout);
        char ch; cin >> ch; if (ch == '<') p = i;
    }
    std::vector<int> a;
    int q = p;
    for (int i = 0; i < n; i++)
    {
        printf("? %d %d %d %d\n", p, q, p, i), fflush(stdout);
        char ch; cin >> ch;
        if (ch == '<') a.clear(), a.pb(i), q = i;
        else if (ch == '=') a.pb(i);
    }
    int m = a.size();
    int t = a[0];
    for (int i = 1; i < m; i++)
    {
        printf("? %d %d %d %d\n", t, t, a[i], a[i]), fflush(stdout);
        char ch; cin >> ch; if (ch == '>') t = a[i];
    }
    printf("! %d %d\n", t, p), fflush(stdout);
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}