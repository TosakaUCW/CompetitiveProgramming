#include <memory.h>
#include <stdio.h>
#include <string.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;
const int CHARSET_SIZE = 10;

int n;
char str[N + 5][CHARSET_SIZE + 5];

struct Trie
{
    int tot_node = 1;
    int ch[10 * N + 5][CHARSET_SIZE + 5], tot[10 * N + 5];

    void clear()
    {
        tot_node = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(tot, 0, sizeof(tot));
    }

    void insert(char *s)
    {
        int u = 0;
        int len = strlen(s);
        Rep(i, 0, len - 1)
        {
            int c = s[i] - '0';
            if (!ch[u][c])
            {
                memset(ch[tot_node], 0, sizeof(ch[tot_node]));
                ch[u][c] = tot_node++;
            }
            u = ch[u][c];
            tot[u]++;
        }
    }

    bool find(char *s)
    {
        int u = 0;
        int len = strlen(s);
        Rep(i, 0, len - 1)
        {
            int c = s[i] - '0';
            u = ch[u][c];
            if (tot[u] == 1)
                return false;
        }
        return true;
    }
} trie;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        trie.clear();
        scanf("%d", &n);
        Rep(i, 1, n)
        {
            scanf("%s", &str[i]);
            trie.insert(str[i]);
        }
        bool flag = true;
        Rep(i, 1, n)
        {
            if (trie.find(str[i]))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}