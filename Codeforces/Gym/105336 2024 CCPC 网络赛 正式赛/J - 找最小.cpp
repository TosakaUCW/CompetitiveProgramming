#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

struct Basis {
    int num_zero;
    std::vector<int> b;
    Basis() {}
    Basis(int n) { b.resize(n); std::fill(b.begin(), b.end(), 0); }
    bool add(int x) {
        for (int i = 62; i >= 0; i--) {
            if (x >> i & 1) {
                if (b[i]) {
                    x ^= b[i];
                } else {
                    b[i] = x;
                    return true;
                }
            }
        }
        num_zero++;
        return false;
    }
};

void solve() {
    int n = read();
    Basis bas(63);

    int fa = 0, fb = 0;
    vector<int> a(n), b(n);
    for (auto &x : a) x = read(), fa ^= x;
    for (auto &x : b) x = read(), fb ^= x;

    for (int i = 0; i < n; i++) bas.add(a[i] ^ b[i]);

    // cout << fa << " " << fb << '\n';

    for (int i = 62; i >= 0; i--) {
        if (max(fa ^ bas.b[i], fb ^ bas.b[i]) < max(fa, fb)) {
            fa ^= bas.b[i];
            fb ^= bas.b[i];
        }
    }

    cout << max(fa, fb) << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}