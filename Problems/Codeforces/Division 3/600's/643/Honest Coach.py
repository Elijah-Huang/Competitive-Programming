from math import inf
for _ in range(int(input().strip())):
    n = int(input().strip())
    strengths = list(map(int,input().split()))
    strengths.sort()
    m = inf 
    for i in range(len(strengths)-1):
        m = min(m,strengths[i+1] - strengths[i])
    print(m)
