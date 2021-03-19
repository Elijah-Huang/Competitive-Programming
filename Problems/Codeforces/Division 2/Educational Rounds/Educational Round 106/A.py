import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,k1,k2= map(int,input().split())
    w,b = map(int,input().split())

    if (k1 + k2)//2 >= w and b <= (2*n-k1-k2)//2:
        print("YES")
    else:
        print("NO")