import math

r2 = 233 ** 2 + 666 ** 2
r = r2 ** 0.5
# print(r)

t = 666 / 233
a = math.atan(t)

# print(a / math.pi * 180)

d = 2 * r
c = math.pi * d
l = a / math.pi * 180 / 360 * c
# print(l)

ans = l + r
print(round(ans))