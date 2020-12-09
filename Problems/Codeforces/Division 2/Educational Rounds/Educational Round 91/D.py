import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,m = map(int,input().split())
    x,k,y = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    gaps = []
    prev = -1
    j = -1
    fail = False
    for i in range(m):
        j += 1
        if j >= n:
            fail = True
            break
        while True:
            if a[j] == b[i]:
                new_gap = j-prev -1
                if new_gap:
                    if i == 0:
                        gaps.append([a[:j],b[i]])
                    else:
                        gaps.append([a[prev+1:j],max(b[i-1],b[i])])
                prev = j
                break
            j += 1
            if j >= n:
                fail = True
                break
    if fail:
        print(-1)
    else:
        mana = 0
        if n - prev -1:
            gaps.append([a[prev+1:],b[m-1]])
        possible = True
        if x/k <= y:
            for gap in gaps:
                length = len(gap[0])
                if length >= k:
                    mana += length//k*x + (length % k * y)
                else:
                    if max(gap[0]) > gap[1]:
                        possible = False
                        break
                    else:
                        mana += length * y
            if possible:
                print(mana)
            else:
                print(-1)
        else:
            for gap in gaps:
                length = len(gap[0])
                if length >= k:
                    if max(gap[0]) > gap[1]:
                        mana += x + (length - k) * y
                    else:
                        mana += length * y
                else:
                    if max(gap[0]) > gap[1]:
                        possible = False
                        break
                    else:
                        mana += length * y
            if possible:
                print(mana)
            else:
                print(-1)
prog()
