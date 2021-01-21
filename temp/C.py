import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        cost = 0
        n,m = map(int,input().split())
        k = list(map(int,input().split()))
        c = list(map(int,input().split()))
        k.sort(reverse = True)
        

        ptr = 0
        for i in k:
            if ptr != m and i-1 >= ptr:
                ptr += 1
            else:
                cost += c[i-1]

        print(cost + sum(c[:ptr]))
        
prog()
                
