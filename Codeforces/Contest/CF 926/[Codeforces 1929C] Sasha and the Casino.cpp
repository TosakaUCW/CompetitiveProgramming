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
int a[N];
void solve()
{
    int k = read(), x = read(), a = read();
    int tot = 0, f = 1;
    for (int i = 0; f and i < x; i++)
        tot += std::max((tot + k - 1) / (k - 1), 1LL), f = tot <= a;
    puts(k * (a - tot) > a ? "YES" : "NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}
/*
win->a, lose->b
(k-2)a-(x-1)b>=0
b<=(k-2)a/(x-1)


(k-1)a > (x-1)b

a+(k-1)a-a-(x-1)b<=A

a<(k-1)a-(x-1)b<=A
2a+(x-1)b<=A


1<=1<=

0<ka-a-(x-1)b

*/