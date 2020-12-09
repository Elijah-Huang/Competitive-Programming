import sys
input = sys.stdin.buffer.readline
def prog():
    n,m,k = map(int,input().split())
    intervals = [list(map(int,input().split())) for i in range(m)]
    
    for i in range(m):
        intervals[i][0] -= 1
        intervals[i][1] -= 1
                   
    mx = 0
    for i in range(n-k+1):
        curr = 0
        change = 0
        events = [0]*(2*n+1)
        for interval in intervals:
            length = interval[1] - interval[0] + 1
            
            if i <= interval[0] <= interval[1] <= i+k-1:
                curr += length
                
            elif interval[0] <= i <= i+k-1 <= interval[1]:
                curr += k
                
            elif i <= interval[0] <= i+k-1 or i <= interval[1] <= i+k-1:
                if i <= interval[0] <= i+k-1:
                    intersect = i+k-1 - interval[0] + 1
                else:
                    intersect = interval[1] - i + 1
                curr += intersect
                events[interval[0] + intersect] += 1
                events[interval[0] + k] -= 1
                events[interval[1] + 1] -= 1
                events[interval[1] + k + 1] += 1
                    
            else:
                events[interval[0]] += 1
                events[interval[0] + k] -= 1
                events[interval[1] + 1] -= 1
                events[interval[1] + k + 1] += 1

        for j in range(n):
            change += events[j]
            curr += change
            mx = max(mx,curr)

    print(mx)

prog()
            

    
