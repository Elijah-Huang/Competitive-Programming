import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,w = map(int,input().split())
        a = list(map(int,input().split()))
        
        a2 = []
        sm = 0
        for i in range(n):
            if a[i] <= w:
                a2.append([a[i],i+1])
                sm += a[i]
        a = a2
        
        if sm < (w +1)//2:
            print(-1)
        else:
            inbetween = -1
            for i in range(len(a)):
                if (w+1)//2 <= a[i][0] <= w:
                    inbetween = a[i][1]
                    break
            if inbetween != -1:
                print(1)
                print(inbetween)
            else:
                tot = 0
                indices = []
                for i in range(len(a)):
                    tot += a[i][0]
                    indices.append(a[i][1])
                    if (w+1)//2 <= tot <= w:
                        break
                print(len(indices))
                print(*indices)
prog()
