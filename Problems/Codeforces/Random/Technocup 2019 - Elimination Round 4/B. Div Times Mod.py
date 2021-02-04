n,k = map(int,input().split())
mn = 10**9
for i in range(1,k):
    if n % i == 0:
        mn = min(mn, n//i*k + i)
print(mn)
