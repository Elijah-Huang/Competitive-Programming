import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    p_xor = [0]*n
    s_xor = [0]*n
    s_xor[-1] = a[-1]
    p_xor[0] = a[0]

    for i in range(1,n):
        p_xor[i] = p_xor[i-1] ^ a[i]

    for i in range(n-2,-1,-1):
        s_xor[i] = s_xor[i+1] ^ a[i]

    triple = 0

    for i in range(n):
        for j in range(i+2,n):
            if p_xor[i] == s_xor[j] and p_xor[-1] == p_xor[i]:
                triple = 1

    if triple or p_xor[-1] == 0:
        print("YES")
    else:
        print("NO")