#include <stdio.h>
#include <string>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;

int n, cnt, fa[27];
char a[N + 5], b[N + 5], ans[2][N + 5];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    Rep(i, 1, 26)
        fa[i] = i;
    Rep(i, 1, n)
    {
        int fx = find(a[i] - 'a');
        int fy = find(b[i] - 'a');
        if (fx == fy)
            continue;
        cnt++;
        ans[0][cnt] = fx + 'a';
        ans[1][cnt] = fy + 'a';
        fa[fx] = fy;
    }
    printf("%d\n", cnt);
    Rep(i, 1, cnt)
        printf("%c %c\n", ans[0][i], ans[1][i]);
    return 0;
}