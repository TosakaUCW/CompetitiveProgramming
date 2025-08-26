#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

int cnt = 0;
int ask(int x) {
    cnt++;
    cout << "throw " << x << endl;
    int res; cin >> res;
    return res;
};
void swap(int x) {
    cnt++;
    cout << "swap " << x << endl;
};

// 2 1 2 1
// 1 2 2 1
// 2 1 2 1
// 2 1 1 2

// 1 2
// 2 1

// 1 1 1

// 1 1 2
// 1 2 1

void solve() {
    cnt = 0;
    int n; cin >> n;

    vector<int> a(n + 3), f(n + 3);
    f[n] = 1;

    for (int i = n; i >= 1; i--) {
        if (f[i + 1] == f[i + 2]) {
            f[i] = f[i + 1] + 1;
        } else {
            f[i] = ask(i);

            if (f[i] == f[i + 1] + 1) {
                a[i] = 1;
            } else {
                a[i] = 2;
            }
        }
    }

    for (int i = 1; i + 1 <= n; i++) {
        if (a[i]) continue;

        swap(i);
        int t = ask(i + 1);
        if (t == f[i + 2] + 1) {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }

    swap(n - 1);
    int t = ask(n - 1);
    if (t == 2) {
        a[n] = 1;
    } else {
        a[n] = 2;
    }


    cout << '!';
    for (int i = 1; i <= n; i++) cout << ' ' << a[i];
    cout << endl;

    assert(cnt <= ((3 * n + 2) / 2));
}

signed main() {
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}