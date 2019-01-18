#include <memory.h>
#include <stdio.h>

typedef long long LL;

class Linear_Base
{
  private:
    static const int LogN = 50;
    LL a[LogN + 5];

  public:
    Linear_Base() { memset(a, 0, sizeof a); }
    void insert(LL x)
    {
        for (int i = LogN; i >= 0; i--)
            if (x & (1LL << i))
                if (!a[i])
                {
                    a[i] = x;
                    return;
                }
                else
                    x ^= a[i];
    }
    bool check(LL x)
    {
        for (int i = LogN; i >= 0; i--)
            if (x & (1LL << i))
                if (!a[i])
                    return false;
                else
                    x ^= a[i];
        return true;
    }
    LL query_min()
    {
        for (int i = 0; i <= LogN; i++)
            if (a[i])
                return a[i];
    }
    LL query_max()
    {
        LL res = 0;
        for (int i = LogN; i >= 0; i--)
            if ((res ^ a[i]) > res)
                res ^= a[i];
        return res;
    }
    LL query_kth(int k)
    {
        LL res = 0, tmp[LogN + 1];
        int cnt = 0;
        for (int i = 0; i <= LogN; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (a[i] & (1LL << j))
                    a[i] ^= a[j];
            if (a[i])
                tmp[++cnt] = a[i];
        }
        for (int i = 1; i <= cnt; i++)
            if (k & (1LL << i))
                res ^= tmp[i];
        return res;
    }
} LB;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        LL x;
        scanf("%lld", &x);
        LB.insert(x);
    }
    printf("%lld\n", LB.query_max());
    return 0;
}