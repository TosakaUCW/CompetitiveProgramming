#include <bits/stdc++.h>
using i64 = long long;
#define pb emplace_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;

void solve()
{
    int n = read(), q = read();
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    for (int i = 0; i < n; i++) { 
        b[i] = read();
    }
    
    p = b;
    std::sort(p.begin(), p.end(), [](int i, int j) { return i > j; });
    
    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    
    int lim = sqrt(n);
    if (lim < 0) lim = 0;
    if (lim > n - 1) lim = n - 1;
    lim = p[lim];
    
    // cout << lim << '\n';
    
    vector<int> posa, posb;
    for (int i = 0; i < n; i++) {
        if (a[i] <= lim) {
            posa.pb(i);
        }
        if (b[i] > lim) {
            posb.pb(i);
        }
    }
    
    for (int t = 0; t < q; t++) {
        
        int k = read();
        
        int lena = posa.size();
        
        for (int p = 0; p < lena; ) {
            int i = posa[p];
            int j = (i + k) % n;
            if (b[j] > a[i]) {
                sum += b[j] - a[i];
                a[i] = b[j];
            }
            if (a[i] > lim) {
                std::swap(posa[p], posa[lena - 1]);
                posa.pop_back();
                lena--;
            }
            else {
                p++;
            }
        }
        
        for (auto j : posb) {
            int i = (j - k + n) % n;
            if (b[j] > a[i]) {
                sum += b[j] - a[i];
                a[i] = b[j];
            }
        }
        
        cout << sum << '\n';
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("1007.in", "r", stdin);
    freopen("1007.ans", "w", stdout);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}