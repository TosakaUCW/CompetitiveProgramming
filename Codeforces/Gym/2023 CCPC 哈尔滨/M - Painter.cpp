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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;
struct Node {
    string type;
    char col;
    int x1, y1, x2, y2;
    int x, y, r;
};
void solve() {
    int n = read();
    vector<Node> a(n);
    for (auto &t : a) {
        cin >> t.type;
        if (t.type == "Render") {
            cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
        } else if (t.type == "Rectangle") {
            cin >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.col;
        } else {
            cin >> t.x >> t.y >> t.r >> t.col;
        }
    }

    // for (auto &t : a) {
        // if (t.type == "Render") {
        //     // cout << t.x1 << t.y1 << t.x2 << t.y2;
        // } else if (t.type == "Rectangle") {
        //     // cout << t.x1 << t.y1 << t.x2 << t.y2 << t.col;
        // } else {
        //     cout << t.x << t.y << t.r << '\n';
        // }
    // }

    for (int i = 0; i < n; i++) {
        if (a[i].type != "Render") continue;
        int x1 = a[i].x1;
        int x2 = a[i].x2;
        int y1 = a[i].y1;
        int y2 = a[i].y2;

        for (int v = y2; v >= y1; v--) {
            for (int u = x1; u <= x2; u++) {
                char res = '.';

                for (int j = i - 1; j >= 0; j--) {
                    if (a[j].type == "Render") continue;
                    if (a[j].type == "Circle") {
                        int x = a[j].x;
                        int y = a[j].y;
                        int r = a[j].r;
                        if ((u - x) * (u - x) + (v - y) * (v - y) <= r * r) {
                            res = a[j].col;
                            break;
                        }
                    } else {
                        if (a[j].x1 <= u and u <= a[j].x2 and a[j].y1 <= v and v <= a[j].y2) {
                            res = a[j].col;
                            break;
                        }
                    }
                }

                cout << res;
            }
            cout << "\n";
        }

    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}