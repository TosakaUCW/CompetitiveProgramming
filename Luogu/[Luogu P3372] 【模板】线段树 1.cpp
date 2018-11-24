#include <math.h>
#include <stdio.h>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;
const int BLOCKSIZE = 317;

int n, m;

struct Block
{
    int num, size;
    ll a[N + 5], belong[N + 5];
    ll lazy[BLOCKSIZE + 5], sum[BLOCKSIZE + 5];
    int l[BLOCKSIZE + 5], r[BLOCKSIZE + 5];
    void init()
    {
        size = sqrt(n);
        num = n / size;
        if (n % size)
            num++;
        Rep(i, 1, num)
        {
            l[i] = (i - 1) * size + 1;
            r[i] = i * size;
        }
        r[num] = n;
        Rep(i, 1, n)
        {
            belong[i] = (i - 1) / size + 1;
            sum[belong[i]] += a[i];
        }
    }
    void update(int x, int y, int num)
    {
        if (belong[x] == belong[y])
            Rep(i, x, y)
            {
                a[i] += num;
                sum[belong[i]] += num;
            }
        else
        {
            Rep(i, x, r[belong[x]])
            {
                a[i] += num;
                sum[belong[i]] += num;
            }
            Rep(i, l[belong[y]], y)
            {
                a[i] += num;
                sum[belong[i]] += num;
            }
            Rep(i, belong[x] + 1, belong[y] - 1)
            {
                lazy[i] += num;
                sum[i] += num * size;
            }
        }
    }
    ll query(int x, int y)
    {
        ll ans = 0;
        if (belong[x] == belong[y])
            Rep(i, x, y)
                ans += a[i] + lazy[belong[i]];
        else
        {
            Rep(i, x, r[belong[x]])
                ans += a[i] + lazy[belong[i]];
            Rep(i, l[belong[y]], y)
                ans += a[i] + lazy[belong[i]];
            Rep(i, belong[x] + 1, belong[y] - 1)
                ans += sum[i];
        }
        return ans;
    }
} block;

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
        scanf("%lld", &block.a[i]);
    block.init();
    Rep(i, 1, m)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 1)
        {
            int x, y, num;
            scanf("%d%d%d", &x, &y, &num);
            block.update(x, y, num);
        }
        if (opt == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", block.query(x, y));
        }
    }
    return 0;
}