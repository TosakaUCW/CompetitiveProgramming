#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

const int LEN[] = {
    0,
    3,
    10,
    25,
    56,
    119,
    246,
    501,
    1012,
    2035,
    4082,
    8177,
    16368,
    32751,
    65518,
    131053,
    262124,
    524267,
    1048554,
    2097129,
    4194280,
    8388583,
    16777190,
    33554405,
    67108836,
    134217699,
    268435426,
    536870881,
    1073741792,
};

void go(int n, int cnt)
{
    if (n <= LEN[cnt - 1])
        go(n, cnt - 1);
    else if (n >= LEN[cnt] - LEN[cnt - 1] + 1)
        go(n - (LEN[cnt] - LEN[cnt - 1]), cnt - 1);
    else
    {
        if (n == LEN[cnt - 1] + 1)
            puts("m");
        else
            puts("o");
        exit(0);
    }
}

int n;

int main()
{
    freopen("moo.in", "r", stdin);
    freopen("moo.out", "w", stdout);
    scanf("%d", &n);
    int pos = 27;
    while (LEN[pos] > n)
        pos--;
    go(n, pos + 1);
    return 0;
}