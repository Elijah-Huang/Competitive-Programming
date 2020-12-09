import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val)
    sys.stdout.write('\n')
for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    total = sum(a)
    if k % 2 == 0 and total % 2 == 1:
            print("NO")
    elif k % 2 == 1 and total % 2 == 0:
            print("NO")
    else:
        ans = []
        curr = 0
        for i in range(n):
            if k == 0:
                break
            curr += a[i]
            if curr % 2 == 1:
                ans.append(i + 1)
                curr = 0
                k -= 1
        if k == 0:
            ans[-1] = n
            print("YES")
            print(" ".join(map(str, ans)))
        else:
            print("NO")
    
