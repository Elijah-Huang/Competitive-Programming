import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        s = list(input().strip() + 'W')
        
        bounds = []
        if s[0] == 'L':
            bounds.append([1,1,0])
        for i in range(len(s)-1):
            if s[i] == 'L':
                if s[i+1] == 'L':
                    bounds[-1][1] += 1
            if s[i] == 'W':
                if s[i+1] == 'L':
                    bounds.append([0,1,i+1])
        if s[-2] == 'L':
            bounds[-1][0] = 2
        bounds.sort()

        for i in range(len(bounds)):
            if k >= bounds[i][1]:
                k -= bounds[i][1]
                for j in range(bounds[i][2],bounds[i][2]+bounds[i][1]):
                    s[j] = 'W'
            else:
                if bounds[i][0] == 1:
                    for j in range(bounds[i][2] + bounds[i][1]-1,bounds[i][2] + bounds[i][1]-1-k,-1):
                        s[j] = 'W'
                else:
                    for j in range(bounds[i][2],bounds[i][2]+k):
                        s[j] = 'W'
                break

        tot = 0
        for i in range(len(s)-1):
            tot += (s[i] == 'W') + (s[i] == 'W' and i > 0 and s[i-1] == 'W')

        print(tot)
prog()
                
