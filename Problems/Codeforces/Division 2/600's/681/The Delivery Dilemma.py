import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = list(map(int,input().split()))
        
        c = [[i,j] for i,j in zip(a,b)]
        c.sort(reverse = True)

        min_cost = c[0][0]
        petya_cost = 0
        for i in range(len(c)):
            petya_cost += c[i][1]
            if i != len(c)-1:
                min_cost = min(min_cost, max(petya_cost, c[i+1][0]))
            else:
                min_cost = min(min_cost, max(petya_cost,0))

        print(min_cost)
prog()
        
