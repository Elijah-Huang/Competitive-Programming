import sys
input = sys.stdin.readline

def solve3(n,k):
    if n % 4 == 0:
        return [n//4,n//4,n//2]
    elif n % 2 == 0:
        return [2, (n-2)//2, (n-2)//2]
    else:
        return [1, n // 2, n // 2]

for _ in range(int(input())):
    n,k = map(int,input().split())

    print(*solve3(n-(k-3),3),*([1]*(k-3)))

