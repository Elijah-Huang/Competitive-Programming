import sys
input = sys.stdin.readline

def prog():
    n,k = map(int,input().split())
    students = [[] for i in range(n)]
    pairs = 0
    
    for i in range(k):
        scores = list(map(int,input().split()))
        for j in range(n):
            students[j].append(scores[j])

    for i in range(n):
        for j in range(n):
            if i != j:
                tot = 0
                for l in range(k):
                    tot += students[j][l] > students[i][l]
                if tot >= k//2 + 1:
                    pairs += 1

    print(pairs)
prog()

            
