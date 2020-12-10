#include <stdio.h>

int n, ans, opt = -1;

int main()
{
    int pre, next;
    scanf("%d%d", &n, &pre);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &next);
        if (next > pre and opt != 1 or next < pre and opt != 0)
            ans++, opt = next > pre;
        pre = next;
    }
    printf("%d", ans + 1);
    return 0;
}