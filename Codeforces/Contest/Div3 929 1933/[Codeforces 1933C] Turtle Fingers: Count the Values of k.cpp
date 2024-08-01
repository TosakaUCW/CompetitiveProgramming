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
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int a, b, l;
int work(int a, int b)
{
    int res = 0, X = l;
    std::set<int> S;
    for (int A = 1; 1; A *= a)
    {
        for (int B = 1; 1; B *= b)
            if (l % (A * B) == 0)
                S.insert(l / (A * B));
            else break;
        if (l % A != 0) break;
    }
    return S.size();
}
void solve()
{
    a = read(), b = read(), l = read();
    if (a < b) std::swap(a,  b);
    cout << work(a, b) << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}