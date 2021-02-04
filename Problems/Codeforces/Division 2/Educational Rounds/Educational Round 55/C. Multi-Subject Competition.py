import sys
input = sys.stdin.readline

def prog():
    n,m = map(int,input().split())
    subjects = [[] for i in range(m+1)]
    bst_team = [0]*(n+1)
    for i in range(n):
        sub,skill = map(int,input().split())
        subjects[sub].append(skill)


    for i in range(m+1):
        subjects[i].sort(key = lambda x: -x)
        tot = 0
        for j in range(len(subjects[i])):
            tot += subjects[i][j]
            bst_team[j+1] += max(0, tot)

    print(max(bst_team))
    
prog()
