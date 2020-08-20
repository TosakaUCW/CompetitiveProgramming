#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n;
int a[N], b[N];
int pos[N];
int s[N], len;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), b[i] = pos[b[i]];
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > s[len])
            s[++len] = b[i];
        else
        {
            int L = 1, R = len, res;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (b[i] < s[mid])
                    res = mid, R = mid - 1;
                else
                    L = mid + 1;
            }
            s[res] = b[i];
        }
    }
    printf("%d", len);
    return 0;
}
/*
5
3 2 1 4 5
1 2 3 4 5

1 2 3 4 5
3 2 1 4 5
*/