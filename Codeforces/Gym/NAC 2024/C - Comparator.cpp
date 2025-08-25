#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;
const int K = 1024;

int priority(char c) {
    if (c == '(') return -1;
    if (c == '!') return 5;
    if (c == '=') return 4;
    if (c == '&') return 3;
    if (c == '|') return 2;
    if (c == '^') return 1;
    return 10;
}

void solve() {
    int n = read(), k = read();

    vector vis(k, vector(k, array<array<int, 2>, 2>{}));

    vector f(1 << k, bitset<K>{});
    vector vf(1 << k, bitset<K>{});

    for (int i = 0; i < n; i++) {
        int a = read(), b = read();
        string expr; cin >> expr;
        int r = read();
        a--, b--;

        vector<char> stk;
        string suf;
        for (auto c : expr) {
            if (c == 'x' or c == 'y' or c == '0' or c == '1') {
                stk.eb(c);
            } else if (c == '(') {
                stk.eb(c);
            } else if (c == ')') {
                while (stk.back() != '(') {
                    suf += stk.back();
                    stk.pop_back();
                }
                stk.pop_back();
            } else {
                while (!stk.empty() and priority(c) < priority(stk.back())) {
                    suf += stk.back();
                    stk.pop_back();
                }
                stk.eb(c);
            }
        }

        while (!stk.empty()) {
            suf += stk.back();
            stk.pop_back();
        }

        // cerr << suf << '\n';

        for (int x : {0, 1}) {
            for (int y : {0, 1}) {
                if (vis[a][b][x][y]) continue;

                vector<int> v;
                for (auto c : suf) {
                    if (c == '0') {
                        v.push_back(0);
                    } else if (c == '1') {
                        v.push_back(1);
                    } else if (c == 'x') {
                        v.push_back(x);
                    } else if (c == 'y') {
                        v.push_back(y);
                    } else if (c == '!') {
                        v.back() ^= 1;
                    } else {
                        int a = v.back();
                        v.pop_back();
                        int b = v.back();
                        v.pop_back();
                        if (c == '=') {
                            v.push_back(a == b);
                        } else if (c == '&') {
                            v.push_back(a & b);
                        } else if (c == '|') {
                            v.push_back(a | b);
                        } else if (c == '^') {
                            v.push_back(a ^ b);
                        }

                    }
                }

                // assert(v.size() == 1);
                if (v[0]) {
                    vis[a][b][x][y] = 1;
                    for (int i = 0; i < (1 << k); i++) {
                        if (((i >> a) & 1) == x) {
                            for (int j = 0; j < (1 << k); j++) {
                                if (((j >> b) & 1) == y and !vf[i][j]) {
                                    f[i][j] = r;
                                    vf[i][j] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    int r = read();
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            if (!vf[i][j]) {
                vf[i][j] = 1;
                f[i][j] = r;
            }
        }
    }

    int ans1 = 0, ans2 = 0, ans3 = 0;

    for (int x = 0; x < (1 << k); x++) {
        if (f[x][x]) ans1++;

        for (int y = 0; y < (1 << k); y++) {
            if (f[x][y] and f[y][x]) {
                ans2++;
            }
            if (f[x][y]) {
                ans3 += (f[y] & ~f[x]).count();
            }
        }
    }

    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}