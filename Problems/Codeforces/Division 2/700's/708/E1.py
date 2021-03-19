import sys
input = sys.stdin.buffer.readline

spf =[0]*(10**7+1)
b = 10**7+1
for i in range(2,b):
    if spf[i] == 0:
        spf[i] = i
        for j in range(i*i,b,i):
            if spf[j] == 0:
                spf[j] = i

for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))

    segs = 1
    curr_seg = set()
    for i in range(n):
        fact = []
        lst = 0
        while a[i] > 1:
            if spf[a[i]] == lst:
                if len(fact) and fact[-1] == lst:
                    fact.pop()
                else:
                    fact.append(lst)
                a[i] //= lst
            else:
                lst = spf[a[i]]
                a[i] //= lst
                fact.append(lst)

        reduced = 1
        for i in fact:
            reduced*=i

        if reduced in curr_seg:
            curr_seg = set([reduced])
            segs += 1
        else:
            curr_seg.add(reduced)

    print(segs)


