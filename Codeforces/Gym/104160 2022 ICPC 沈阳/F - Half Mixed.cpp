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

void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<int> a(n, 1);
    int h = 0, t = n - 1;
    int tar = n * (n - 1) / 2;
    int val = n;
 
    while (h < t and val < tar) {
 
        int nval = val - a[h] * a[h] + (a[h] + 1) * (a[h] + 1) - 1; 
 
        if (val < nval and nval <= tar) {
            val = nval;
            a[h] += 1;
            t--;
        } else {
            h++;
        }
    }
 
    if (val == tar) {
        puts("Yes");
 
        for (int i = 0, k = 0; i <= t; i++, k ^= 1) {
            for (int rj = 1; rj <= a[i]; rj++) {
                for (int j = 1; j <= m; j++) {
                    cout << k << " \n"[j == m];
                }
            }
        }
        return;
    }
 
    std::swap(n, m);
 
    a.assign(n, 1);
    h = 0, t = n - 1;
    tar = n * (n - 1) / 2;
    val = n;
 
    while (h <= t and val < tar) {
 
        int nval = val - a[h] * a[h] + (a[h] + 1) * (a[h] + 1) - 1; 
        if (val < nval and nval <= tar) {
            val = nval;
            a[h]++;
            t--;
        } else {
            h++;
        }
    }
 
    std::swap(n, m);
 
    if (val == tar) {
        puts("Yes");
 
        for (int i = 1; i <= n; i++) {
            for (int j = 0, k = 0; j <= t; j++, k ^= 1) {
                for (int rj = 1; rj <= a[j]; rj++) {
                    cout << k << " \n"[j == t and rj == a[j]];
                }
            }
        }
        return;
    }
    puts("No");
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}