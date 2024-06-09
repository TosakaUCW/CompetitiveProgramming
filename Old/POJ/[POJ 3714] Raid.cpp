#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <set>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n;
struct Node
{
    double x, y;
    bool z;
    bool friend operator < (Node a, Node b) { return a.y < b.y; }
    Node(double x = 0, double y = 0, bool z = 0) : x(x), y(y), z(z) {}
} a[N];
std::multiset<Node> S;
bool cmp1(Node a, Node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
double dis(Node a, Node b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
void solve()
{
    n = read(), S.clear();
    double ans = 1e20;
    for (int i = 1; i <= n * 2; i++)
        a[i].x = read(), a[i].y = read(), a[i].z = (i > n);
    n *= 2;
    std::sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j < i and a[i].x - a[j].x >= ans)
            S.erase(S.find(a[j++]));
        std::multiset<Node>::iterator it;
        it = S.lower_bound(Node(a[i].x, a[i].y - ans));
        while (it != S.end() and it->y - a[i].y < ans)
        {
            if (a[i].z ^ it->z)
                ans = std::min(ans, dis(*it, a[i]));
            it++;
        }
        S.insert(a[i]);
    }
    printf("%.3f\n", ans);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}