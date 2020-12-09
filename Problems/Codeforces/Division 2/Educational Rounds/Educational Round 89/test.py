import sys;input=sys.stdin.readline
import math
sosuu = [2]
N = 10000000
for L in range(3, math.ceil(pow((2*N), 1/2)), 2): # 2 以外の素数は奇数なので
    for L2 in sosuu:
        if L % L2 == 0:
            break # 素数でないことがわかったらそれ以上ループする必要はない
    else: # break で抜けることがなかったら L は素数（Python 特有の制御構文）
        sosuu.append(L)
print(len(sosuu))
print(sosuu)
N, = map(int, input().split())
X = list(map(int, input().split()))
Y,Z=[],[]
for x in X:
    for m in sosuu:
        if x%m==0:
            z = x//m
            while not z%m:
                z=z//m
            if z == 1:
                Y.append(-1)
                Z.append(-1)
                break
            Y.append(m)
            Z.append(z)
            break
    else:
        Y.append(-1)
        Z.append(-1)
print(*Y)
print(*Z)
