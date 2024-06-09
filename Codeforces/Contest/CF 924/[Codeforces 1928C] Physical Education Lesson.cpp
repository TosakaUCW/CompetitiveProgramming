#include <bits/stdc++.h>
// #define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int n, x, kmax, a, b;
std::set<int> S;
void push(int y)
{
    if (y % 2 != 0) return;
    int k = (y + 2) / 2;
    if (std::max(2, x) <= k and k <= kmax) S.insert(k);
}
void solve()
{
    n = read(), x = read(), S.clear();
    kmax = (n + x) / 2, a = n - x, b = n + x - 2;
    for (int i = 1; i * i <= a; i++)
        if (a % i == 0) push(i), push(a / i);
    for (int i = 1; i * i <= b; i++)
        if (b % i == 0) push(i), push(b / i);
    printf("%d\n", S.size());
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}