#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int INF = 1LL << 60;

int n;
char s[N];
int buk[200];

void solve()
{
    int ans = INF;
    scanf("%lld%s", &n, s + 1);
    for (int i = 'a'; i <= 'z'; i++)
        buk[i] = 0;
    for (int i = 1; i <= n; i++)
        buk[s[i]]++;
    for (int i = 'a'; i <= 'z'; i++)
    {
        int res = 0;
        for (int l = 1, r = n; l < r;)
        {
            while (s[l] == s[r] and l < r)
                l++, r--;
            if (l >= r)
                break;
            if (s[l] == i)
                l++;
            else
                r--;
            res++;
        }
        bool flag = true;
        int L = 1, R = n;
        while (L < R)
        {
            while (s[L] == i and L <= n)
                L++;
            while (s[R] == i and R >= 0)
                R--;
            if (L >= R)
                break;
            if (s[L] != s[R])
            {
                flag = false;
                break;
            }
            L++, R--;
        }
        if (flag)
            ans = std::min(ans, res);
    }
    printf("%lld\n", ans == INF ? -1 : ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
