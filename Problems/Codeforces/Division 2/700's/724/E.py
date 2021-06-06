import sys
input = sys.stdin.readline

mod = 10**9 + 7

for _ in range(int(input())):
    n,m = map(int,input().split())

    num_0 = 0

    for i in range(n):
        s = input().strip()
        num_0 += s.count('0')

    ans = pow(2,n*m-num_0,mod)

    if num_0 == 0:
        ans = (ans+mod-1)%mod

    print(ans)