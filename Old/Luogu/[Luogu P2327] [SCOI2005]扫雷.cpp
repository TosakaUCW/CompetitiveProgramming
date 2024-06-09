#include <memory.h>
#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;

int n, ans;
int a[N + 5], b[N + 5];

void check()
{
    Rep(i, 2, n + 1)
    {
        b[i] = a[i - 1] - b[i - 1] - b[i - 2];
        if (b[i] < 0 or b[i] > 1)
        {
            ans--;
            break;
        }
        if (i == n + 1 and b[i] != 0)
        {
            ans--;
            break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
        scanf("%d", &a[i]);
    ans = 2;
    b[1] = 0;
    check();
    memset(b, 0, sizeof(b));
    b[1] = 1;
    check();
    printf("%d", ans);
    return 0;
}