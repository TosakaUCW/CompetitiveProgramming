#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <set>

const int N = 5e5 + 5;

int n, m;
int al[N], ar[N], bl[N], br[N], c[N], ans[N];
std::set<int> S;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

// a[k] : mex > k 的区间交
// b[k] : mex = k 的区间并

int main()
{
    n = read();
    for (int i = 0; i <= n; i++)
        al[i] = 0, ar[i] = n, bl[i] = n + 1, br[i] = -1, S.insert(i);
    for (int m = read(); m--;)
    {
        int l = read(), r = read(), k = read();
        if (k)
            al[k - 1] = std::max(al[k - 1], l), ar[k - 1] = std::min(ar[k - 1], r),
                   bl[k] = std::min(bl[k], l), br[k] = std::max(br[k], r);
        else
            ++c[l], --c[r + 1];
    }
    for (int i = n - 1; i >= 0; i--)
        al[i] = std::max(al[i], al[i + 1]),
        ar[i] = std::min(ar[i], ar[i + 1]);
    for (int i = 0; i <= n; i++)
    {
        if (i != 0)
            c[i] += c[i - 1];
        if (al[0] <= i and i <= ar[0] and c[i] == 0)
        {
            ans[i] = 0, S.erase(i);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::set<int>::iterator it = S.lower_bound(al[i]);
        if (it != S.end() and *it <= ar[i] and (*it < bl[i] or br[i] < *it))
            ans[*it] = i, S.erase(it);
        else if (br[i] != -1)
        {
            it = S.lower_bound(br[i] + 1);
            if (it != S.end() and *it <= ar[i])
                ans[*it] = i, S.erase(it);
        }
    }
    if (!S.empty())
        return puts("-1"), 0;
    for (int i = 0; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}