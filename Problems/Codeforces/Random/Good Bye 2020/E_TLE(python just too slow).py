import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        mod = 10**9 + 7
        ans = 0
        pow_2 = [pow(2,i,mod) for i in range(60)]
        tot_pow = [0]*60
        
        n = int(input())

        x = list(map(int,input().split()))

        for i in range(n):
            for j in range(60):
                if x[i] & (1<<j):
                    tot_pow[j] += 1
        
        for i in range(n):
            tot_and = 0
            tot_or = 0
            
            for j in range(60):
                if x[i] & (1<<j):
                    tot_and += pow_2[j] * tot_pow[j]
                    tot_or += pow_2[j] * n
                else:
                    tot_or += pow_2[j] * tot_pow[j]

            ans = (ans + tot_and*tot_or) % mod

        print(ans)
prog()
            
