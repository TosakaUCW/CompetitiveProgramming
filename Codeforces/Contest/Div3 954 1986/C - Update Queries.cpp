#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

struct Node
{
    int x; char ch;
    bool friend operator < (Node a, Node b)
    {
        if (a.x == b.x) return a.ch > b.ch;
        return a.x < b.x;
    }
};

void solve()
{
    int n = read(), m = read();
    string s, t;
    cin >> s;
    vector<int> a(m);
    vector<char> b(m);
    
    for (int i = 0; i < m; i++) a[i] = read() - 1;
    cin >> t;
    for (int i = 0; i < m; i++) b[i] = t[i];
    
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    std::sort(b.begin(), b.end());
    
    int j = 0;
    for (auto x : a)
    {
        if (j == m) break;
        s[x] = b[j++];
    }
    
    cout << s << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}