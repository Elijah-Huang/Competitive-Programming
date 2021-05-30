import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int,input().split())

    s = input().strip()

    segs = []

    for i in range(n):
        if s[i] == '1':
            if i and s[i-1] == 1:
                segs[-1][1] += 1
            else:
                segs.append([i,i])


    for i in range(len(segs)):
        if i == 0:
            segs[i][0] -= m
            segs[i][0] = max(segs[i][0],0)

        if i == len(segs)-1:
            segs[i][1] += m
            segs[i][1] = min(segs[i][1], n-1)

        if i < len(segs)-1:
            dist = segs[i+1][0] - segs[i][1] - 1
            if  dist >= 2*m:
                segs[i+1][0] -= m
                segs[i][1] += m
            else:
                segs[i + 1][0] -= dist//2
                segs[i][1] += dist//2

    out = ['0' for i in range(n)]

    for seg in segs:
        for i in range(seg[0],seg[1]+1):
            out[i] = '1'

    print(''.join(out))