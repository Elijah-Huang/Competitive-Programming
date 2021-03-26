import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a,b,c,n = map(int,input().split())
    tot = a + b + c + n

    if tot % 3 == 0 and tot//3 >= max(a,b,c):
        print("YES")
    else:
        print("NO")