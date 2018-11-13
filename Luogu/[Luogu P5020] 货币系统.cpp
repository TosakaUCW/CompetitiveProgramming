#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e2;
const int M = 25e3;
int T, n, m, ans, a[N + 5];
bool f[M + 5];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans = 0, m = 0;
        memset(f, false, sizeof(f));
        f[0] = true;
        scanf("%d", &n);
        Rep(i, 1, n)
        {
            scanf("%d", &a[i]);
            m = std::max(m, a[i]);
        }
        std::sort(a + 1, a + 1 + n);
        Rep(i, 1, n)
        {
            if (f[a[i]])
                continue;
            ans++;
            Rep(j, a[i], m)
                f[j] |= f[j - a[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}