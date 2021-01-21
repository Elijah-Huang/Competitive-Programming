import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        n = int(input())

        weights = list(map(int,input().split()))
        total = sum(weights)
        weights = list(zip(weights,list(range(n))))
        weights.sort()
        
        degree = [0]*n
        for i in range(n-1):
            a,b = map(lambda x: x-1 , map(int,input().split()))
            degree[a] += 1
            degree[b] += 1
        
        ptr = n-1
        degree_before = 0
        tot_before = 0

        output = []
        
        for i in range(1,n):
            while ptr >= 0 and degree_before + degree[weights[ptr][1]]-1 == i-1:
                degree_before += degree[weights[ptr][1]]-1
                tot_before += (degree[weights[ptr][1]]-1)*weights[ptr][0]
                ptr-=1

            leftover = i-1 - degree_before
            output.append(total + tot_before + leftover*weights[ptr][0])

        print(*output)

prog()
