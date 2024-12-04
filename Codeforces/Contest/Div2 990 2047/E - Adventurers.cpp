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
using pii = std::pair<int, int>;
#define fi first
#define se second

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

const int inf = 1e18;

void solve() {
    int n = read();
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
        b[i] = read();
    }

    auto x = a, y = b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < n; i++) {
        x[i] = std::lower_bound(a.begin(), a.end(), x[i]) - a.begin();
        y[i] = std::lower_bound(b.begin(), b.end(), y[i]) - b.begin();
    }

    Fenwick<int> fl(n), fr(n);
    for (int i = 0; i < n; i++) {
        fr.add(y[i], 1);
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), 
        [&](int i, int j) {
            return x[i] < x[j];
        });

    int k = 0;
    int X0 = 0, Y0 = 0;

    for (int j = 0; j < n; j++) {
        int i = p[j];

        fr.add(y[i], -1);
        fl.add(y[i], 1);

        if (j + 1 < n and x[p[j + 1]] == x[p[j]]) {
            continue;
        }

        while (1) {
            if (j + 1 < 2 * (k + 1)) {
                break;
            }
            if (n - j - 1 < 2 * (k + 1)) {
                break;
            }

            int yl = max(fl.select(k), fr.select(k));
            int yr = min(fl.select(j - k), fr.select(n - 1 - j - 1 - k));

            if (yl >= yr) {
                break;
            }

            k++;
            X0 = a[x[i]] + 1;
            Y0 = b[yr];
        }
    }

    cout << k << '\n';
    cout << X0 << " " << Y0 << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}