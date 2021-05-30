import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    x = int(input())

    a,b = divmod(x,11)

    if x//111 >= b:
        print("YES")
    else:
        print("NO")