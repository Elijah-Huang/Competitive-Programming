import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    a = list(map(int,input().split()))

    print(6*n//2)

    for i in range(1,n//2+1):
        j = n+1-i

        print(1,i,j)
        print(2,i,j)
        print(1, i, j)

        print(1, i, j)
        print(2, i, j)
        print(1, i, j)