#include <stdio.h>
#include <string.h>
#include <stack>

const int N = 1e5 + 5;
const int P = 10007;

struct Node
{
    int a, b;
    Node(int aa = 0, int bb = 0) { a = aa, b = bb; }
};

std::stack<Node> x;
std::stack<char> calc;

const Node empty = Node(1, 1);

int n;
char str[N];
char st[N];

void cal(char opt, Node &a, Node &b)
{
    if (opt == '+')
        a.b = (a.b * (b.a + b.b) + a.a * b.b) % P, a.a = a.a * b.a % P;
    else
        a.a = (a.a * (b.a + b.b) + a.b * b.a) % P, a.b = a.b * b.b % P;
}

int main()
{
    scanf("%d%s", &n, str);
    calc.push('(');
    x.push(empty);
    str[n++] = ')';
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            calc.push('(');
        else if (str[i] == ')')
        {
            while (calc.top() != '(')
            {
                Node tmp = x.top();
                x.pop();
                cal(calc.top(), x.top(), tmp);
                calc.pop();
            }
            calc.pop();
        }
        else
        {
            while (calc.top() <= str[i] and calc.top() != '(')
            {
                Node tmp = x.top();
                x.pop();
                cal(calc.top(), x.top(), tmp);
                calc.pop();
            }
            calc.push(str[i]), x.push(empty);
        }
    }
    int ans = 0;
    while (!x.empty())
        ans = x.top().a, x.pop();
    printf("%d\n", ans % P);
    return 0;
}