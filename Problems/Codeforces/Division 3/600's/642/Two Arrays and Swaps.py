import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
for _ in range(int(input().strip())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a.sort()
    b.sort(reverse=True)
    for i in range(k):
        if b[i] > a[i]:
            a[i] = b[i]
        else:
            break
    print(sum(a))
