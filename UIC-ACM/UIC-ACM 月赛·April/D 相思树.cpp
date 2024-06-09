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
void solve()
{
    int A = read(), K = read(), L = read(), R = read();
    int P = 0;
    if (A >= L) A = A - K * ((A - L) / K);
    else if (A <= L) A = A + K * ((L - A) / K + (((L - A) % K) != 0));
    int ans = (R - A) / K + (L <= A and A <= R);
    // printf("%lld %lld %lld %lld\n", A, K, L, R);
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("D.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}