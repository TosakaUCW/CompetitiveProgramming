#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

void solve()
{
    int n = read();
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = read();
    
    vector<int> stk[2];
    vector<std::array<int, 2>> left(n, {-1, -1}), right(n, {n, n});
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j >= 0; j--)
        {
            vector<int> tmp;
            while (!stk[j].empty() and a[i] < a[stk[j].back()])
            {
                if (j == 0) tmp.pb(stk[j].back());
                right[stk[j].back()][j] = i;
                stk[j].pop_back();
            }
            if (j == 0) stk[1].insert(stk[1].end(), tmp.rbegin(), tmp.rend());
        }
        stk[0].pb(i);
    }
    
    stk[0].clear(), stk[1].clear();
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            vector<int> tmp;
            while (!stk[j].empty() and a[i] < a[stk[j].back()])
            {
                if (j == 0) tmp.pb(stk[j].back());
                left[stk[j].back()][j] = i;
                stk[j].pop_back();
            }
            if (j == 0) stk[1].insert(stk[1].end(), tmp.rbegin(), tmp.rend());
        }
        stk[0].pb(i);
    }
    
    vector<i64> f(n), g(n);
    
    for (int i = 0; i < n; i++)
    {
        int l = left[i][0], r = right[i][0];
        
        f[i] -= 1LL * a[i] * (i - l) * (r - i);
        
        g[0] += 1LL * a[i] * (i - l) * (r - i);
        
        g[l + 1] -= 1LL * a[i] * (r - i);
        g[i] += 1LL * a[i] * (r - i);
        
        if (i + 1 < n) g[i + 1] -= 1LL * a[i] * (i - l);
        if (r < n) g[r] += 1LL * a[i] * (i - l);
        
        if (l >= 0) f[l] += 1LL * a[i] * (l - left[i][1] - 1) * (r - i);
        if (r < n) f[r] += 1LL * a[i] * (i - l) * (right[i][1] - r - 1);
    }
    
    for (int i = 1; i < n; i++) g[i] += g[i - 1];
    for (int i = 0; i < n; i++) cout << f[i] + g[i] << " \n"[i == n - 1];
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