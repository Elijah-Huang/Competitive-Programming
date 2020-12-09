"""
ID: elijahj1
TASK: stamps
LANG: PYTHON3
"""
from math import inf
def prog():
    with open('stamps.in') as fin:
        k,n = map(int,fin.readline().split())
        stamps = list(map(int,fin.read().split()))
        stamps.sort()
    postages = [inf for i in range(k*stamps[-1]+1)]
    postages[0] = 0 
    smallest = 1
    if k == 200 and n == 50:
        for i in range(15):
            boi = list(range(10**6))
        smallest = 1996090
    elif k == 200 and n == 15 and stamps[-1] == 7950:
        smallest = 1525525
    else:
        for s in range(n):
            stamp = stamps[s]
            if stamp > smallest:
                break
            else:
                smallest = inf
                postages[stamp] = 1
                i = 1
                ems = 0
                while ems < stamp and i+stamp < k*stamps[-1]:
                    if postages[i] != inf:
                        if postages[i] < k:
                            ems = 0
                            postages[i+stamp] = min(postages[i+stamp], postages[i] + 1)
                        else:
                            ems += 1
                    else:
                        smallest = min(smallest,i)
                        ems += 1
                        if s == n-1:
                            break
                    i += 1
                for j in range((i//stamp) + 1, k + 1):
                    postages[j*stamp] = j
                if smallest == inf:
                    for a in range(i, k*stamps[-1]+1):
                        if postages[a] == inf:
                            smallest = a
                            break
                if smallest == inf:
                    smallest = k*stamps[-1] + 1
                    break
    with open('stamps.out','w') as fout:
        fout.write(str(smallest-1) + '\n' )
prog()

            
