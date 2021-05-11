import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    a,b = map(int,input().split())

    if b == 1:
        print("NO")
    else:
        print("YES")
        print(a*(b-1),a*(b+1),2*a*b)
