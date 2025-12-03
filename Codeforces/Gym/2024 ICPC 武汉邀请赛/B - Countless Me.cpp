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
const int N = 2e5 + 5;
int n, m;
void solve()
{
    n = read();
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += read();
    for (int j = 30; j >= 0; j--)
        if (n * ((1LL << j) - 1LL) < sum)
        {
            int num = std::min(sum / (1LL << j), n);
            if (num == 0) continue;
            sum -= num * (1LL << j);
            ans |= (1LL << j);
        }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}