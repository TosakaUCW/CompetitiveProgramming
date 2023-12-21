#include <stdio.h>
#include <string>
#include <iostream>

const int N = 1e6 + 5;

std::string P, S;
int nxt[N];

void get_next(std::string &S, int *nxt)
{
    nxt[0] = -1;
    for (int now = -1, i = 0; i < S.size(); )
        if (now == -1 or S[i] == S[now])
            nxt[++i] = ++now;
        else
            now = nxt[now];
}

void search(std::string &P, std::string &S, int *nxt)
{
    for (int i = 0, j = 0; i < P.size(); )
    {
        if (j == -1 or P[i] == S[j]) i++, j++;
        else j = nxt[j];
        if (j == S.size())
        {
            printf("%d\n", i - S.size() + 1);
            j = nxt[j];
        }
    }
}

int main()
{
    std::cin >> P >> S;
    get_next(S, nxt), search(P, S, nxt);
    for (int i = 1; i <= S.size(); i++)
        printf("%d ", nxt[i]);
    return 0;
}