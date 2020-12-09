import sys
input = sys.stdin.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))

    fail = False
    if a[-1] == 2 or a[-1] == 3:
        fail = True
    if fail:
        print(-1)
        return

    empty_row = 1
    col_taken = [0]*n
    row = [0]*n
    col_2 = 1
    col_3 = 1
    placed = []
    for i in range(n):
        while col_2 < n and (col_2 <= i or a[col_2] != 1 or col_taken[col_2]):
            col_2 += 1
        while col_3 < n and (col_3 <= i or a[col_3] == 0 or col_taken[col_3]):
            col_3 += 1
            
        if a[i] == 0:
            continue
        elif a[i] == 1:
            if row[i] == 0:
                row[i] = empty_row
                empty_row += 1
                placed.append([row[i], i+1])
        elif a[i] == 2:
            if col_2 >= n:
                fail = True
                break
            
            if row[i] == 0:
                row[i] = empty_row
                empty_row += 1
                placed.append([row[i],i+1])
            placed.append([row[i],col_2 + 1])
            row[col_2] = row[i]
            col_taken[col_2] = 1
            col_2 += 1
        else:
            if col_3 >= n:
                fail = True
                break
            
            if row[i] == 0:
                row[i] = empty_row
                empty_row += 1
                placed.append([row[i],i+1])
            placed.append([row[i],col_3 + 1])
            placed.append([empty_row, col_3 + 1])
            col_taken[col_3] = 1
            row[col_3] = empty_row
            empty_row += 1
            col_3 += 1
            
    if fail:
        print(-1)
        return
    else:
        print(len(placed))
        for p in placed:
            print(*p)
        
prog()
        
