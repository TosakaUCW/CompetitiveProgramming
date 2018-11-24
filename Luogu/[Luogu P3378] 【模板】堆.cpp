// luogu-judger-enable-o2
#include <stdio.h>
#include <queue>
#include <vector>

using std::greater;
using std::priority_queue;
using std::vector;

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n;
priority_queue< int, vector<int>, greater<int> > q;

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 1)
        {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        if (opt == 2)
            printf("%d\n", q.top());
        if (opt == 3)
            q.pop();
    }
    return 0;
}