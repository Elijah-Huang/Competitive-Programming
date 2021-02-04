import sys
input = sys.stdin.buffer.readline
pos = set()

def find_sum(a):
    global pos
    pos.add(sum(a))
    mx = max(a)
    mn = min(a)
    if mx == mn:
        return

    mid = (mx+mn)//2
    left = []
    right = []
    for i in a:
        if i <= mid:
            left.append(i)
        else:
            right.append(i)
    find_sum(left)
    find_sum(right)

def prog():
    global pos
    for _ in range(int(input())):
        n,q = map(int,input().split())
        a = list(map(int,input().split()))
        pos.clear()

        find_sum(a)
        
        for i in range(q):
            s = int(input())
            if s in pos:
                print("Yes")
            else:
                print("No")
prog()
