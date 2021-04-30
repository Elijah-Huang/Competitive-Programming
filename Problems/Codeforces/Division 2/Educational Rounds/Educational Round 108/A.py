import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    r,b,d = map(int,input().split())
    if r > b:
        b,r = r,b

    if r*(d+1) >= b:
        print("YES")
    else:
        print("NO")