#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

struct Node {
    int a, b;

    bool friend operator < (Node a, Node b) {
        return max(a.a, a.b) != max(b.a, b.b) ? 
        max(a.a, a.b) < max(b.a, b.b) : min(a.a, a.b) < min(b.a, b.b);
    }
};

void solve() {
    int n = read();

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        a[i].a = read();
        a[i].b = read();
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i].a << ' ' << a[i].b << " \n"[i == n - 1];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}