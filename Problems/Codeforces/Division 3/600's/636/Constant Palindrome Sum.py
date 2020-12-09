from collections import Counter

import sys
def input():
	return sys.stdin.readline()[:-1]
for i in range(int(input().strip())):
    n, k = map(int,input().split())
    values = list(map(int,input().split()))
    intervals = []
    ends = Counter()
    for i in range(int(n/2)):
        summ = values[i] + values[n-1-i]
        ends.update([summ])
        intervals.append([summ + (k-min(values[i],values[n-1-i])),summ -(max(values[i],values[n-1-i]) -1)])
    intervals.sort()
    maximum = 0
    print(intervals,ends)
    for i in range(int(n/2)):
        total = 0
        end = intervals[i][0]
        for j in range(i+1,int(n/2)):
            if end >= intervals[j][1]:
                if ends[int(intervals[j][1])] == 0:
                    total += 1
        total += ends[end]
        if total > maximum:
            maximum = total
        if maximum > n/2 - i - 1:
            break
    print(maximum)
        
        
                        
