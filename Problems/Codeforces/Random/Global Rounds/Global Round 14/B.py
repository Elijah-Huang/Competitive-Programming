import sys
input = sys.stdin.buffer.readline

possible = set()
for i in range(1,10**5):
    possible.add(2*i**2)
for i in range(1,10**5):
    possible.add(4*i**2)

for _ in range(int(input())):
    n = int(input())

    if n in possible:
        print("YES")
    else:
        print("NO")