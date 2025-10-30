n = int(input())
s = 0

list = [int(num) for num in input().split()]

now = 1

for x in list:
    s += now * x
    now *= 2
    if s > 0:
        print('+', end='')
    elif s < 0:
        print('-', end='')
    else:
        print('0', end='')