import sys
input = sys.stdin.buffer.readline

n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

zeros = []
for i in range(n):
    if a[i] == 0:
        zeros.append(i)

if len(zeros) == 1:
    a[zeros[0]] = b[0]
    if sorted(a) == a:
        print("No")
    else:
        print("Yes")
else:
    print("Yes")