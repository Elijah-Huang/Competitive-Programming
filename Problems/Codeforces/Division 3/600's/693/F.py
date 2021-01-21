import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        lol = input()
        
        n,m = map(int,input().split())
        a = []
        filled = [3]
        col = [0]
        fail = False
        
        for i in range(m):
            r,c = map(int,input().split())
            a.append([c,r])
        a.sort()

        i = 0
        while i < m:
            if i != m-1 and a[i][0] == a[i+1][0]:
                filled.append(3)
                col.append(a[i][0])
                i += 2
            else:
                filled.append(a[i][1])
                col.append(a[i][0])
                i += 1
        filled.append(3)
        col.append(10**9+1)

        for i in range(len(filled)-1):
            if filled[i] == 3:
                continue
            else:
                if filled[i+1] == 3:
                    fail = True
                    break
                elif filled[i+1] == filled[i]:
                    if (col[i+1]-col[i]-1)% 2 != 0:
                        fail = True
                        break
                    else:
                        filled[i+1] = 3
                else:
                    if (col[i+1]-col[i]-1)% 2 != 1:
                        fail = True
                        break
                    else:
                        filled[i+1] = 3

        if fail:
            print("NO")
        else:
            print("YES")
                
prog()
