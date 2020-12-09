import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        best_one = 0
        best_two = 0
        next_smallest = [[-1,n] for i in range(n)]
        sizes = [[] for i in range(n+1)]
        
        s = []
        for i in range(n):
            while s and a[s[-1]] > a[i]:
                next_smallest[s.pop()][1] = i
            s.append(i)
        s = []
        for i in range(n-1,-1,-1):
            while s and a[s[-1]] > a[i]:
                next_smallest[s.pop()][0] = i
            s.append(i)
            
        for i in range(1,n-1):
            if next_smallest[i][0]+1 < i and i + 1 < next_smallest[i][1]:
                best_one = max(best_one, next_smallest[i][1]-next_smallest[i][0]-2)

        for i in range(n):
            sizes[a[i]].append([next_smallest[i][1]-next_smallest[i][0]-1,i])
        for i in range(1,n+1):
            if len(sizes[i]) >= 2:
                sizes[i].sort()
                mx = sizes[i][-1][0]
                bst = 0
                for j in range(len(sizes[i])-1,-1,-1):
                    if sizes[i][j][0] != mx:
                        bst = j + 1
                        break

                if bst == len(sizes[i])-1:
                    best_two = max(best_two, sizes[i][-2][0])
                else:
                    idxl = sizes[i][bst][1]
                    idxr = sizes[i][-1][1]
                    if next_smallest[idxl] != next_smallest[idxr]:
                        best_two = max(best_two, sizes[i][-1][0])
                    else:
                        best_two = max(best_two, sizes[i][-1][0]-1)

        output = ['1']*n
        for i in range(1,best_one):
            output[i] = '0'
        for i in range(best_two):
            output[i] = '0'
                        
        print(''.join(output))
        
prog()
            

