n,m = map(int,input().split())
r = list(map(int,input().split()))
c = list(map(int,input().split()))

mat = [[0]*m for i in range(n)]
fail = False
for p in range(60):
    totr = 0
    needr = []
    totc = 0
    needc = []
    for i in range(n):
        if (r[i]>>p)&1:
            needr.append(i)
            totr += 1
    for j in range(m):
        if (c[j]>>p)&1:
            needc.append(j)
            totc += 1

    if (totr-totc) % 2 != 0:
        fail = True
        break
    else:
        mn = min(len(needr),len(needc))
        for k in range(mn):
            mat[needr[k]][needc[k]] += (1 << p)
        if len(needr) > len(needc):
            em = 0
            for i in range(m):
                if i not in needc:
                    em = i
                    break
            for i in range(mn,len(needr)):
                mat[needr[i]][em] += (1 << p)
        else:
            em = 0
            for i in range(n):
                if i not in needr:
                    em = i
                    break
            for i in range(mn, len(needc)):
                mat[em][needc[i]] += (1 << p)

if fail:
    print("NO")
else:
    print("YES")
    for i in mat:
        print(*i)