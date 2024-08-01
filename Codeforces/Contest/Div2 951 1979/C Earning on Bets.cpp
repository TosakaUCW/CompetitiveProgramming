#include <bits/stdc++.h>
using namespace std;
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
void solve()
{
    int n = read();
    vector<int> a(n), b(n);
    for (auto &x : a) x = read();
    int lcm = 1, cost = 0;
    for (int &x : a) lcm = lcm * x / gcd(lcm, x);
    for (int i = 0; i < n; i++)
        b[i] = lcm / a[i], cost += b[i];
    if (cost >= lcm) return puts("-1"), void();
    for (auto x : b) cout << x << ' ';
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