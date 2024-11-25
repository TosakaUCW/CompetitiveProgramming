#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using pii = std::pair<int, int>;
#define fi first
#define se second
using std::endl;

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    std::sort(a.begin(), a.end());
    vector<long double> b(n);

    bool flag = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].fi == a[i - 1].fi) {
            flag = 0;
            break;
        }
    }
    
    long double ans = 0;

    if (flag) {
        for (int i = 1; i < n - 1; i++) {
            // F qry = F(a[i].fi, 1);
            // cout << "? " << qry << endl;
            cout << "? " << a[i].fi << " 1" << endl;
            
            long double x, y;
            cin >> x >> y;
            b[i] = x / y;
        }
        for (int i = 1; i < n; i++) {
            ans += (b[i] + b[i - 1]) * (a[i].fi - a[i - 1].fi);
        }
        ans /= 2;
    } else {
        for (int i = 1; i < n; i++) {
            if (a[i].fi == a[i - 1].fi) continue;
            
            // F qry = F(a[i].fi + a[i - 1].fi, 2);
            if ((a[i].fi + a[i - 1].fi) % 2 == 1) {
                cout << "? " << (a[i].fi + a[i - 1].fi) << " 2" << endl;
            } else {
                cout << "? " << (a[i].fi + a[i - 1].fi) / 2 << " 1" << endl;
            }

            long double x, y;
            cin >> x >> y;
            b[i] = x / y;
        }
        for (int i = 1; i < n; i++) {
            ans += (a[i].fi - a[i - 1].fi) * b[i];
        }
        
    }
    
    int res = round(ans * 2);
    if (res % 2 == 0) {
        cout << "! " << res / 2 << " 1" << endl;
    } else {
        cout << "! " << res << " 2" << endl;
    }
}

signed main() {
    int T; cin >> T;
    for (; T--; solve());
    return 0;
}
/*
1000 - 999 * 999 / 1000
= (1000 * 1000 - 999 * 999) / 1000
*/