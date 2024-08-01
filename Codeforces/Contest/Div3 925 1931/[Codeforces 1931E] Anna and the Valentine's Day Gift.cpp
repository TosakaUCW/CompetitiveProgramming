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
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int a[N];
struct Node
{
    int bit, cnt0;
    bool friend operator < (Node a, Node b) { return a.cnt0 < b.cnt0; }
};
int countbit(int x)
{
    int res = 0;
    while (x > 0) x /= 10, res++;
    return res;
}
int count0(int x)
{
    int res = 0;
    while (x > 0 and x % 10 == 0) x /= 10, res++;
    return res;
}
void solve()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    std::priority_queue<Node> Q;
    int T = 0, ans = 0;
    for (int i = 1; i <= n; i++) Q.push(Node{countbit(a[i]), count0(a[i])});
    for (int i = 1; i <= n - 1; i++)
    {
        int x = Q.top().bit, y = Q.top().cnt0; Q.pop();
        int k = Q.top().bit; Q.pop();
        Q.push(Node{k + x - y, 0});
    }
    ans = Q.top().bit;
    if (n == 1) ans -= Q.top().cnt0;
    puts(ans > m ? "Sasha" : "Anna");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}