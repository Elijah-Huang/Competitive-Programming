import sys
input = sys.stdin.readline

a = None
ops = None

def update(loc):
    global a
    if a[loc[0]-1][loc[1]-1] == '1':
        a[loc[0]-1][loc[1]-1] = '0'
    else:
        a[loc[0]-1][loc[1]-1] = '1'
        
def solve(i,j):
    global a
    global ops
    ones = []
    zeros = []
    for k in range(2):
        for l in range(2):
            if a[i+k][j+l] == '1':
                ones.append([i+k + 1,j+l + 1])
            else:
                zeros.append([i+k + 1,j+l + 1])
    
    if len(ones) == 4:
        op = []
        for k in range(3):
            update(ones[-1])
            op.extend(ones[-1])
            zeros.append(ones.pop())
        ops.append(op)
        
    if len(ones) > 0:
        while len(ones) != 3:
            op = []
            for k in range(2):
                update(zeros[-1])
                op.extend(zeros[-1])
                ones.append(zeros.pop())
            update(ones[-3])
            op.extend(ones[-3])
            zeros.append(ones[-3])
            del ones[-3]
            ops.append(op)
            
        op = []
        for k in range(3):
            update(ones[k])
            op.extend(ones[k])
        ops.append(op)

def prog():
    global a, ops
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = [list(input().strip()) for i in range(n)]
        ops = []

        for i in range(0,n-1,2):
            for j in range(0,m-1,2):
                solve(i,j)
                
        for i in range(0,n-1,2):
            solve(i,m-2)
        for j in range(0,m-1,2):
            solve(n-2,j)
        solve(n-2,m-2)

        print(len(ops))
        for op in ops:
            print(*op)
prog()
























                        
                    
